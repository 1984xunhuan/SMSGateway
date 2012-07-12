/**
 *
 *@file ByteStream.hpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-03
 *
 */

#ifndef BYTESTREAM_H_
#define BYTESTREAM_H_

#include <vector>
#include <string>

using namespace std;

class ByteStream
{
public:
    ByteStream()
    {
        this->vByteStream.push_back(0);
    }
    
    ~ByteStream()
    {
    }
    
    int GetSize()
    {
        return this->vByteStream.size() - 1;
    }
    
    void Clear()
    {
        int len = this->GetSize();
            
        if (len > 0)
        {
            vByteStream.erase(vByteStream.begin(), vByteStream.end());
            vByteStream.push_back(0);
        }
    }

    
    int GetBytes(unsigned int start, unsigned int offsize, unsigned char* pbuf)
    {
        if (start > this->vByteStream.size())
        {
                return -1;
        }

        unsigned int len = start + offsize >
        this->vByteStream.size() ? vByteStream.size() - start : offsize;

        memcpy(pbuf, (unsigned char*)(&(this->vByteStream[start])), len);

        return len;
    }
          
    void Append(unsigned char* pbuf, unsigned int len)
    {
        this->vByteStream.pop_back();
        
        for(unsigned int i=0; i<len; i++)
        {
            this->vByteStream.push_back(pbuf[i]);
        }
        
        this->vByteStream.push_back(0);
    }
    
    const unsigned char* operator [](unsigned int offsize)
    {
        if (offsize >= this->vByteStream.size() && offsize != 0)
        {
            return NULL;
        }

        return (unsigned char*)(&(this->vByteStream[offsize]));
    }
    
    friend ByteStream& operator << (ByteStream& bs, char c)
    {
        bs.vByteStream.pop_back();
        bs.vByteStream.push_back((unsigned char)c);
        bs.vByteStream.push_back(0);
        
        return bs;
    }
    
    friend ByteStream& operator << (ByteStream& bs, unsigned char c)
    {
        bs.vByteStream.pop_back();
        bs.vByteStream.push_back(c);
        bs.vByteStream.push_back(0);
        
        return bs;
    }

    friend ByteStream& operator << (ByteStream& bs, const string& in)
    {
        bs<<in.c_str();
        
        return bs;
    }

    friend ByteStream& operator << (ByteStream& bs, string& in)
    {
        bs<<in.c_str();
        
        return bs;
    }

    friend ByteStream& operator << (ByteStream& bs, const char* in)
    {
        unsigned int len = strlen(in);
        
        if (len > 0)
        {
            bs.Append((unsigned char*)(in), len);
        }
        
        return bs;
    }

    friend ByteStream& operator << (ByteStream& bs, ByteStream& in)
    {
        bs.Append(const_cast<unsigned char*>(in[0]), in.GetSize());
        
        return bs;
    }

    friend ByteStream& operator << (ByteStream& bs, long in)
    {
        char long_in[100];
        unsigned int len = snprintf(long_in, 100, "%ld", in);    
        bs.Append((unsigned char*)long_in, len);
        
        return bs;
    }

    friend ByteStream& operator << (ByteStream& bs, unsigned long in)
    {
        char long_in[100];
        unsigned int len = snprintf(long_in, 100, "%lu", in);
        bs.Append((unsigned char*)long_in, len);
        
        return bs;
    }

    friend ByteStream& operator << (ByteStream& bs, int in)
    {
        char long_in[100];
        unsigned int len = snprintf(long_in, 100, "%d", in);
        bs.Append((unsigned char*)long_in, len);
        
        return bs;
    }

    friend ByteStream& operator << (ByteStream& bs, unsigned int in)
    {
        char long_in[100];
        unsigned int len = snprintf(long_in, 100, "%u", in);
        bs.Append((unsigned char*)long_in, len);
        
        return bs;
    }
    
    friend ByteStream& operator << (ByteStream& bs, short in)
    {
        char long_in[100];
        unsigned int len = snprintf(long_in, 100, "%hd", in);
        bs.Append((unsigned char*)long_in, len);
        
        return bs;
    }
    
    friend ByteStream& operator << (ByteStream& bs, unsigned short in)
    {
        char long_in[100];
        unsigned int len = snprintf(long_in, 100, "%hu", in);
        bs.Append((unsigned char*)long_in, len);
        
        return bs;
    }

    friend ByteStream& operator << (ByteStream& bs, double in)
    {
        char long_in[100];
        unsigned int len = snprintf(long_in, 100, "%f", in);
        bs.Append((unsigned char*)long_in, len);
        
        return bs;
    }
             
    
private:
    vector<unsigned char> vByteStream;
    
};

#endif
