MOD = 1_000_000_007

def pw(k):
  res, t = 1, 2
  while k > 0:
    if k % 2 == 1:
      res = (res * t) % MOD
    t = (t * t) % MOD
    k //= 2
  return res

n = int(input())
for _ in range(n):
  s1 = input()
  s2 = input()
  ans, k = 0, 0
  for i in range(len(s1)):
    if s1[i] == s2[i]:
      if s1[i] == 'O':
        ans = -1
        break
      k += 1
  if ans < 0:
    print(0)
  else:
    print(pw(k))