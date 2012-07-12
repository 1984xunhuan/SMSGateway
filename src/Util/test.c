#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dec_to_hex_1(unsigned char *hex, int hexlen, long dec)
{     
		int i = 0; 
		int temp; 
		unsigned char tempc[16]; 
		
		tempc[0] = '0'; 
		tempc[1] = '1'; 
		tempc[2] = '2'; 
		tempc[3] = '3'; 
		tempc[4] = '4'; 
		tempc[5] = '5'; 
		tempc[6] = '6'; 
		tempc[7] = '7'; 
		tempc[8] = '8'; 
		tempc[9] = '9'; 
		tempc[10] = 'A'; 
		tempc[11] = 'B'; 
		tempc[12] = 'C'; 
		tempc[13] = 'D'; 
		tempc[14] = 'E'; 
		tempc[15] = 'F'; 
		
		memset(hex, 0, hexlen);
		
		while(dec > 0)
		{ 
				temp = (int)dec % 16;//强制转换为int类型 
				
				printf("temp=%d",temp);
				hex[i] = tempc[temp];//把余数转换成字符 
				dec  = dec / 16; 
				i++; 
		}
		
		return i;
} 

char * strReverse(char *des ,char *src, int bytes)
{
    long i,j;
    
    i = bytes-1;
    for(j=0; i>=0; i--,j++)
    {
        *(des+j) = *(src+i);
    }
    
    return des;
}

int dec_to_hex(unsigned char *hex, int hexlen, long dec)
{     
		long i = 0,j=0;
    unsigned char  curchr;
    unsigned char  buf[15];
    
    memset(hex, 0, hexlen);
    while(1)
    {
        curchr =  dec % 16;
        buf[i] = curchr&0x0f;
        
        dec = dec/16;
        if(dec <=0 )    
        {
            i++;
            break;
        }
        
        curchr =  dec % 16;
        buf[i] = buf[i]|((curchr<<4)&0xf0);
        i++;
        dec = dec/16;
        if(dec <=0 )    
        {
            break;
        }
    }
  
    strReverse((char*)(hex+hexlen-i),(char*)buf, i);
    
    return i;
} 

int Hex2Char(int hex)
{
        if(hex < 0xa) return hex+'0';
        else return hex-0xa+'a';
}
        
char* Hex2String(char* buffer, unsigned char* hex, int bytes)
{
        int i;
        if(buffer == NULL)
        	{
        		return NULL;
        		}
               // buffer = (char*) malloc( bytes * 2 + 1);

        for(i = 0; i < bytes; ++i)
        {
                buffer[i*2] =   Hex2Char((hex[i] >> 4) & 0x0f);
                buffer[i*2+1] = Hex2Char((hex[i]) & 0x0f);
        }

        buffer[i*2] = 0;
        return buffer;
}

char* dec2hex(char* p, unsigned int n) 
{ 
      int   i; 
      
      for(i=0;i <8;i++) 
              p[i]= '0'; 
              
      p[8]=0; 
      
      i=7; 
      
      while(n> 0) 
      { 
            unsigned int   m=n%16; 
            
            if(m <=9) 
                  p[i]=m+48; 
            else     
                  p[i]=m+55; 
            n/=16; 
            
            i--;
        } 
        
        return   p; 
}

int main(int argc, char** argv)
{
	  int i = 0;
	  int hexlen = 10;
	  unsigned char hex[10];
	  unsigned int dec = 0;
	  char buffer[10];
	  
	  if(argc < 2)
	  {
	      printf("argc >= 2 \n");
	      
	      //exit(0);
	      
	      argv[1] = "2147483656";
	  }
	  
	  printf("argv[1]=%s\n", argv[1]);
	  
	  dec = 2147483656;//(unsigned int)atol((const char*)argv[1]);
	  
	  printf("dec=%u\n", dec);
	  
	  dec2hex(buffer, dec) ;
	  
	  printf("buffer=%s\n\n", buffer);
	  
    hexlen = dec_to_hex(hex, hexlen, dec);
    
    printf("hex=%s  ====   hexlen=%d\n\n", hex, hexlen);
    
    Hex2String(buffer, hex, hexlen);
    
    printf("buffer=%s  ====   hexlen=%d\n\n", buffer, hexlen);
    
    for(i = 0; i < hexlen; i++)
    {
        printf("%02X", hex[i]);
    }
    
    printf("\n\n");
    
    for(i = 0; i < hexlen*2; i++)
    {
        printf("%c", buffer[i]);
    }
    
    printf("\n\n");
}
