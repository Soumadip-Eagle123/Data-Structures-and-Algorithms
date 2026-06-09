#Recursive solution with string slicing
class Solution:
    def Helper(self, ip, op, ans):
        if len(ip)==0:
            ans.append(op)
            return
     #   s = []
        for i in range(0, len(ip)):
          #  if ip[i] not in s:
            #    s.append(ip[i])
                new_ip = ip[0:i]+ip[i+1 : len(ip)]
                new_op = op + ip[i]
                self.Helper(new_ip, new_op, ans)
        return
    def permutation(self, s):
        v = []
        s = "".join(sorted(s))
        self.Helper(s, "", v)
        v.sort()
        return v
    
#Backtracking solution with swapping
class Solution:
    def Helper(self, index, ip, ans):
        if index == len(ip):
            ans.append("".join(ip))
            return
            
     #   s = set()
        for i in range(index, len(ip)):
         #   if ip[i] in s:
            #    continue
        #    s.add(ip[i])
            ip[index], ip[i] = ip[i], ip[index]
            self.Helper(index + 1, ip, ans)
            ip[index], ip[i] = ip[i], ip[index]
            
        return

    def permutation(self, s):
        v = []
        s = "".join(sorted(s))
        s = list(s)
        self.Helper(0, s, v)
        v.sort()
        return v