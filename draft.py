fi = open("paint.in", "r")
a, b = map(int, fi.readline().split())
c, d = map(int, fi.readline().split())
fo = open("paint.out", "w")
painted = [0] * 101
for i in range(a, b):
  painted[i] = 1
for i in range(c, d):
  painted[i] = 1
fo.write(str(sum(painted)))