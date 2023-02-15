#include <iostream>
using namespace std;

int msb(int x) {
    union { double a; int b[2]; };
    a = x;
    return (b[1] >> 20) - 1023;
}

int highestOneBit(int i) {
    // HD, Figure 3-1
    i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    return i - ((unsigned)i >> 1);
}

int test1(std::uint32_t a){
//	return 32-__builtin_clz(a);
	return (!a)? 0 : test1(a >> 1)+1 ;
}

int highest_bit(std::uint8_t a){
	if( !a ){ return 0; }
	std::uint8_t b;
	b = (a >> 4);
	if( b ){
		a = (b >> 2);
		if( a ){
			b = (a >> 1);
			if( b ){
				return 8;
			}else{
				return 7;
				}
		}else{
			b = (b >> 1);
			if( b ){
				return 6;
			}else{
				return 5;
				}
			}
	}else{
		a = (a >> 2);
		if( a ){
			b = (a >> 1);
			if( b ){
				return 4;
			}else{
				return 3;
				}
		}else{
			b = (b >> 1);
			if( b ){
				return 2;
			}else{
				return 1;
				}
			}
		}
	}
int highest_bit(std::uint16_t a){
	std::uint8_t b = (std::uint8_t)(a >> 8);
	if( b ){
		return highest_bit(b)+8;
	}else{
		return highest_bit((std::uint8_t)a);
		}
	}
int highest_bit(std::uint32_t a){
	#if 1
	std::uint16_t b = (std::uint16_t)(a >> 16);
	if( b ){
		return highest_bit(b)+16;
	}else{
		return highest_bit((std::uint16_t)a);
		}
	#else
	return (!a)? 0 : highest_bit(a >> 1)+1 ;
	#endif
	}
	
int main() {
	printf("%d\n",msb(10));
	printf("%d\n",highestOneBit(10));
	printf("%d\n",highest_bit(std::uint32_t(10)));
    double t1, t2;
    const int lim = 200 * 1000 * 1000;
    {
    	t1 = clock();
    	for (int i = 0; i < lim; i++) {
			int t = msb(i);
			if (t == -42) return 1;
		}
		t2 = clock();
		cout << (t2 - t1) / 1000.0 << endl;
    }
    {
    	t1 = clock();
    	for (int i = 0; i < lim; i++) {
			int t = highestOneBit(i);
			if (t == -42) return 1;
		}
		t2 = clock();
		cout << (t2 - t1) / 1000.0 << endl;
    }
    {
    	t1 = clock();
    	for (int i = 0; i < lim; i++) {
			int t = highest_bit((std::uint32_t)i);
			if (t == 32) return 1;
		}
		t2 = clock();
		cout << (t2 - t1) / 1000.0 << endl;
    }
}
