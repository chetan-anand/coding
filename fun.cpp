#include<iostream>
using namespace std;
int i;
void b() { cout<<i++<<endl; }
void c() { b(); b(); b(); b(); b(); }
void a() { c(); c(); c(); c(); c(); }
int main()
{
    i=1;
    a(); a(); a(); a();
}