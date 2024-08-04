class euclid:
    def __init__(self,n1,n2) -> None:
        
        assert n1 != 0
        assert n2 != 0

        self.num1=n1
        self.num2=n2
        if self.num1 > self.num2:
            t= self.num1
            self.num1=self.num2
            self.num2=t
        self.lcm = max(n1,n2)
        self.hcf = min(n1,n2)

    @staticmethod
    def isPrime(num:int) -> bool:
        if num<=1:
            return False
        if num <=3 or num==5:
            return True
        if num%2 == 0 or num%3 == 0:
            return False
        i=6
        while i*i <= num:
            if(num%(i+1)==0 or num&(i-1)==0):
                return False
            i+=6
        return True

    def euclid_with_recursion(self):
        a = self.num1
        b = self.num2
        def helper(a,b):
            if a == 0:
                return
            self.hcf = a
            a = b%a
            b = self.hcf
            helper(a,b)
        helper(a,b)
        self.lcm = (self.num1 * self.num2)//self.hcf
    def euclid_without_recursion(self):
        a= self.num1
        b= self.num2
        while a!=0:
            self.hcf= a
            a = b%a
            b = self.hcf
        self.lcm = (self.num1 * self.num2)//self.hcf

    def conitinous_int_check(self):
        while self.num1%self.hcf != 0 or self.num2%self.hcf !=0:
            self.hcf-=1
        self.lcm = (self.num1 * self.num2)//self.hcf
    def middle_school(self):
        a=self.num1
        b=self.num2
        i=2
        self.hcf =1
        while i*i <= a or i*i <= b:
            if self.isPrime(i):
                while a%i ==0 and b%i ==0:
                    self.hcf *=i
                    a//=i
                    b//=i
                while a%i == 0:
                    a//=i
                while b%i == 0:
                    b//=i
            i+=1
        self.lcm = (self.num1 * self.num2)//self.hcf


number_of_testcases = int(input('Enter the number of test cases: '))

while number_of_testcases:
    a = int(input('Enter first number :\t'))
    b= int(input('Enter second number :\t'))
    c = euclid(a,b)
    # c.euclid_with_recursion()
    # c.euclid_without_recursion()
    c.middle_school()
    # c.conitinous_int_check()
    print(f'LCM of the 2 numbers is\t{c.lcm}\nHCF of the 2 numbers is\t{c.hcf}')
    number_of_testcases-=1