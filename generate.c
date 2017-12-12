#include <stdio.h>
int generate(int v1, int v2, int constant)
{  
  int t1; 
  int t2; 

  for(int i=0; i<8;++i)
  {
      if(i == 0)
        t1 = v2;          // initialize t1
      else
        t1 = t1 >> 1;     // t1 = t3 / 2;
      t2 = (v1 >> i) & 1; // is the bit even or odd
      if((t1 - t2) % 2)   // one of t1 t2 is odd, the other is even
          t1 = t1 ^ (constant - t2);
      else
          t1 = t1 - t2;
  }  
  return t1>>1;
}

int main(int argc, char **argv)
{
    int v1 = 1;
    int v2 = 0xF985;
    int constant = 0x1064B;
    int ret;

    ret = generate(v1, v2, constant);
    printf("%X\n",ret);  
}