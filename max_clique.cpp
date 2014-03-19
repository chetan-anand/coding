#include <iostream>
#include <sstream>
#include <vector>
 

 
// #define DEBUG
 
/*
  smly::find_cliques: a pivoting version of
  Bron-Kerbosch algorithm
 
  url: git.io/bk73
  comment: ぴぼっとザンス
 
  ## References:
 
  - Bron, C. and Kerbosch, J. 1973.
  Algorithm 457: finding all cliques of an undirected graph.
  (http://dl.acm.org/citation.cfm?id=362367)
  - Etsuji Tomita, Akira Tanaka, Haruhisa Takahashi,
  The worst-case time complexity for generating all maximal
  cliques and computational experiments.
  (http://dl.acm.org/citation.cfm?id=1217600)
  - F. Cazals, C. Karande,
  A note on the problem of reporting maximal cliques.
  (http://dl.acm.org/citation.cfm?id=1450505)
 
 */
 
namespace smly {
 
class Gr {
 public:
  typedef size_t gr_size_type;
  typedef size_t vertex_descriptor;
  typedef std::ptrdiff_t vertex_difference;
  typedef boost::unordered_set<vertex_descriptor> vertex_set;
  typedef boost::unordered_map<
    vertex_descriptor,
    vertex_set
    >::const_iterator internal_vertex_iterator;
 
 public:
  Gr ()
      : nbrs_()
  { }
 
  class vertex_iterator
      : public boost::iterator_adaptor<
    vertex_iterator,
    internal_vertex_iterator,
    vertex_descriptor,
    boost::forward_traversal_tag,
    vertex_descriptor,
    vertex_difference>
  {
    friend class boost::iterator_core_access;
 
   public:
    explicit vertex_iterator( internal_vertex_iterator it )
        : iterator_adaptor_( it )
    { }
 
   private:
    vertex_descriptor dereference() const
    {
      return iterator_adaptor_::base_reference()->first;
    }
    void increment() {
      ++base_reference();
    }
  }; // class vertex_iterator
 
  vertex_iterator begin() const
  {
    return vertex_iterator( nbrs_.begin() );
  }
 
  vertex_iterator end() const
  {
    return vertex_iterator( nbrs_.end() );
  }
 
  gr_size_type size() const
  {
    return nbrs_.size();
  }
 
  static vertex_descriptor null_vertex()
  {
    return std::numeric_limits<vertex_descriptor>::max();
  }
 
  gr_size_type degree_size(const vertex_descriptor& v) const
  {
    auto it = nbrs_.find(v);
    if (it == nbrs_.end()) return false;
    return it->second.size();
  }
 
  bool is_connected(
      const vertex_descriptor& v1,
      const vertex_descriptor& v2) const
  {
    auto it = nbrs_.find(v1);
    if (it == nbrs_.end()) return false;
    return (it->second.find(v2) != it->second.end());
  }
 
  void load(std::istream& in)
  {
    std::string line;
    while (getline(in, line)) {
      if (line.empty()) continue;
 
      std::stringstream ss(line);
      vertex_descriptor cost, src, dst;
      ss >> cost >> src >> dst;
      add_edge(src, dst);
    }
  }
 
 private:
  boost::unordered_map<
   vertex_descriptor,
   boost::unordered_set<vertex_descriptor>
   > nbrs_;
 
  void add_edge(
      const vertex_descriptor& src,
      const vertex_descriptor& dst)
  {
    nbrs_[src].insert(dst);
  }
 
}; // class Gr
 
Gr::vertex_descriptor pivot(
    const Gr& g,
    const Gr::vertex_set& p,
    const Gr::vertex_set& x)
{
  Gr::vertex_set base;
  for (auto it = p.begin(); it != p.end(); ++it)
    base.insert(*it);
  for (auto it = x.begin(); it != x.end(); ++it)
    base.insert(*it);
 
  Gr::vertex_descriptor picked = Gr::null_vertex();
  for (auto it = base.begin(); it != base.end(); ++it) {
    if (picked == Gr::null_vertex() ||
        g.degree_size(picked) < g.degree_size(*it)) {
      picked = *it;
    }
  }
  return picked;
}
 
void nbr_intersection(
    const Gr& g,
    Gr::vertex_descriptor v,
    const Gr::vertex_set& s,
    Gr::vertex_set& ret)
{
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (g.is_connected(v, *it)) {
      ret.insert(*it);
    }
  }
}
 
void bron_kerbosch_pivot(
    const Gr::gr_size_type& threshold,
    const Gr& g,
    std::vector<Gr::vertex_set>& vs,
    Gr::vertex_set& r,
    Gr::vertex_set& p,
    Gr::vertex_set& x)
{
  if (p.empty() && x.empty()) {
    if (r.size() > threshold) {
      vs.push_back(Gr::vertex_set());
      std::copy(
          r.begin(),
          r.end(),
          inserter(vs.back(), vs.back().begin()));
    }
  } else {
    auto u = pivot(g, p, x);
 
    Gr::vertex_set rems;
    for (auto it = p.begin(); it != p.end(); ++it)
      if (!g.is_connected(u, *it))
        rems.insert(*it);
 
    for (auto it = rems.begin(); it != rems.end(); ++it) {
      Gr::vertex_descriptor v = *it;
      Gr::vertex_set new_r, new_p, new_x;
      std::copy(r.begin(), r.end(), inserter(new_r, new_r.begin()));
      new_r.insert(v);
      nbr_intersection(g, v, p, new_p);
      nbr_intersection(g, v, x, new_x);
 
      bron_kerbosch_pivot(threshold, g, vs, new_r, new_p, new_x);
 
      p.quick_erase(p.find(v));
      x.insert(v);
    }
  }
}
 
void find_cliques(
    const Gr& g,
    std::vector<Gr::vertex_set>& vs)
{
  Gr::vertex_set r, p, x;
  std::copy(g.begin(), g.end(), inserter(p, p.begin()));
  bron_kerbosch_pivot(2, g, vs, r, p, x);
}
 
} // namespace smly
 
int main()
{
  smly::Gr g;
 
#ifdef DEBUG
  /* sample_input:
   *   12 - 11   1425
   *   |  x  | /  |
   *   8 -- 10 - 1426
   *
   */
  std::stringstream sample_input;
  sample_input << "1       8       10"     << std::endl
               << "1       8       11"     << std::endl
               << "1       8       12"     << std::endl
               << "1       10      8"      << std::endl
               << "1       10      11"     << std::endl
               << "1       10      12"     << std::endl
               << "1       10      1425"   << std::endl
               << "1       10      1426"   << std::endl
               << "1       11      8"      << std::endl
               << "1       11      10"     << std::endl
               << "1       11      12"     << std::endl
               << "1       12      8"      << std::endl
               << "1       12      10"     << std::endl
               << "1       12      11"     << std::endl
               << "1       1425    10"     << std::endl
               << "1       1425    1426"   << std::endl
               << "1       1426    10"     << std::endl
               << "1       1426    1425"   << std::endl;
  g.load(sample_input);
#else
  g.load(std::cin);
#endif
 
  std::vector<smly::Gr::vertex_set> vvs;
  smly::find_cliques(g, vvs);
 
  std::for_each(
      vvs.begin(),
      vvs.end(),
      [&](const smly::Gr::vertex_set& vs) {
        std::cout << "clique:";
        std::for_each(
            vs.begin(),
            vs.end(),
            [&](const smly::Gr::vertex_descriptor v) {
              std::cout << ' ' << v;
            });
        std::cout << std::endl;
      });
}