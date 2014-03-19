from collections import Counter
r = 0
c = 0

def update(monster, monsters , covered, m_1, c_1):
	#c_1 = covered[:]
	#m_1 = monsters[:]
	c1 = []
	for o in monsters:
		m_1.append(o)
		c1.append(o[2])
	arena = max(c1)

	for p in covered:
		c_1.append(p)

	for i in range(monster[0]+1,r):			#moving rightwards
		if (i,monster[1]) in covered:
			break
		else :
			c_1.append((i,monster[1]))
			if (i,monster[1],monster[2]) in monsters:
				m_1.remove((i,monster[1],monster[2]))

	for i in range(monster[0]-1,-1,-1):     #moving leftwards
		if (i,monster[1]) in covered:
			break
		else :
			c_1.append((i,monster[1]))
			if (i,monster[1],monster[2]) in monsters:
				m_1.remove((i,monster[1],monster[2]))

	for i in range(monster[1]+1,c):			#moving downwards
		if (monster[0], i) in covered:
			break
		else :
			c_1.append((monster[0],i))
			if (monster[0],i,monster[2]) in monsters:
				m_1.remove((monster[0],i,monster[2]))

	for i in range(monster[1]-1,-1,-1):			#moving upwards
		if (monster[0], i) in covered:
			break
		else :
			c_1.append((monster[0],i))
			if (monster[0],i,monster[2]) in monsters:
				m_1.remove((monster[0],i,monster[2]))

	m_1.remove(monster)
	c_1.append(monster)

	m2 = m_1[:]
	m_1 = []
	for mon in m2:
		if mon[0] < monster[0] and mon[1] < monster[1]:
			m_1.append((mon[0], mon[1] , arena))
		elif mon[0] < monster[0] and mon[1] > monster[1]:
			m_1.append((mon[0], mon[1] , arena+1))
		elif mon[0] > monster[0] and mon[1] < monster[1]:
			m_1.append((mon[0], mon[1] , arena+2))
		else :
			m_1.append((mon[0], mon[1] , arena+3))


	# print '-----'
	# print monster
	# print monsters
	# print covered
	# print m_1
	# print c_1

def winner(monsters, covered):
	if len(monsters) == 0:
		return False
	elif len(monsters) == 1:
		return True
	elif len(monsters) == 2:
		if(monsters[0][0] == monsters[1][0]):
			indi = 0
			for i in range(min(monsters[0][1], monsters[1][1]), max(monsters[0][1], monsters[1][1])):
				if (monsters[0][0], i) in covered:
					indi =1
					break
			if indi ==1 :
				return False
			else :
				return True
		elif(monsters[0][1] == monsters[1][1]):
			indi = 0
			for i in range(min(monsters[0][0], monsters[1][0]), max(monsters[0][0], monsters[1][0])):
				if (i , monsters[0][1]) in covered:
					indi =1
					break
			if indi ==1 :
				return False
			else :
				return True
		else :
			return False
	else:
		a1 = []
		b1 = []
		c1 = []
		for mon in monsters:
			a1.append(mon[0])
			b1.append(mon[1])
			c1.append(mon[2])
		l = len(monsters)
		if (len(set(a1)) == l and len(set(b1)) == l) or (len(set(c1)) == l):
			if l%2 == 0:
				return False
			else :
				return True




		for monster in monsters:
			m_1 = []
			c_1 = []
			update(monster , monsters , covered, m_1, c_1)
			#print 'Player plays :' + str(monster) + " :: update : " + str(m_1) + " : " + str(c_1)
			ind = 0
			for mon in m_1:
				m_2 = []
				c_2 = []
				update(mon , m_1 , c_1, m_2, c_2)
				if not winner(m_2,c_2):
					#print 'Losing when chosen :' + str(monster)
					ind = 1 
					break
			if ind == 0:
				#print 'Winning when chosen :' + str(monster) + " monsters left : " + str(m_1)
				return True
		return False



t = input()
while t>0:
	t-=1
	[r ,c] = map(int,raw_input().split())
	mat = []
	for i in range(r):
		mat.append(list(raw_input()))
	
	monsters = []
	rr = []
	rc = []
	for i in range(2,r-2):
		for j in range(2,c-2):
			if mat[i][j] != '#':
				if mat[i-1][j]=='^' and mat[i-2][j]=='^' and mat[i+1][j]=='^' and mat[i+2][j]=='^' and mat[i][j-1]=='^' and mat[i][j-2]=='^'and mat[i][j+1]=='^' and mat[i][j+2]=='^':
					monsters.append((i-2,j-2))
					rr.append(i-2)
					rc.append(j-2)

	if monsters ==[]:
		print 'Kirito'
		continue

	temp = []
	if rr == []:
		rr.append(0)
	if rc == []:
		rc.append(0)
	r1 = Counter(rr)
	c1 = Counter(rc)
	for mon in monsters:
		temp.append((mon,r1[mon[0]]+c1[mon[1]]))
	temp.sort(key=lambda x: x[1], reverse=True)
	#print temp
	#print monsters
	monsters = []
	for tup in temp:
		monsters.append((tup[0][0], tup[0][1], 0))

	r = max(rr)+1
	c = max(rc)+1

	#print monsters
	covered = []
	if winner(monsters, covered) :
		print 'Asuna'
	else :
		print 'Kirito'
