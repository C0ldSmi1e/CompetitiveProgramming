// 构造函数（1）
bitset<4> bitset1;  // 无参构造，长度为 4 ，默认每一位为 0 
bitset<8> bitset2(12);  // 长度为 8 ，二进制保存，前面用 0 补充

string s = "100101"
bitset<10> bitset3(s);  // 长度为 10 ，前面用 0 补充

char s2[] = "10101";
bitset<13> bitset4(s2);  // 长度为 13 ，前面用 0 补充

cout << bitset1 << endl;  // 0000
cout << bitset2 << endl;  // 00001100
cout << bitset3 << endl;  // 0000100101
cout << bitset4 << endl;  // 0000000010101

// 构造函数（2）
// 在进行有参构造时，若参数的二进制表示比 bitset 的 size 小，则在前面用 0 补充；
// 若比 size 大，参数为整数时取后面部分，参数为字符串时取前面部分
bitset<2> bitset1(12);  // 12 的二进制为 1100 （长度为 4 ），但 bitset1 的 size=2 ，只取后面部分，即 00

string s = "100101";
bitset<4> bitset2(s);  // s的 size=6 ，而 bitset 的 size=4 ，只取前面部分，即 1001

char s2[] = "11101";
bitset<4> bitset3(s2);  //与 bitset2 同理，只取前面部分，即 1110

cout << bitset1 << endl;  // 00
cout << bitset2 << endl;  // 1001
cout << bitset3 << endl;  // 1110

// 操作符
bitset<4> foo (string("1001"));
bitset<4> bar (string("0011"));

cout << (foo^=bar) << endl;  // 1010 (foo对bar按位异或后赋值给foo)
cout << (foo&=bar) << endl;  // 0010 (按位与后赋值给foo)
cout << (foo|=bar) << endl;  // 0011 (按位或后赋值给foo)

cout << (foo<<=2) << endl;  // 1100 (左移 2 位，低位补 0 ，有自身赋值)
cout << (foo>>=1) << endl;  // 0110 (右移 1 位，高位补 0 ，有自身赋值)

cout << (~bar) << endl;  // 1100 (按位取反)
cout << (bar<<1) << endl;  // 0110 (左移，不赋值)
cout << (bar>>1) << endl;  // 0001 (右移，不赋值)

cout << (foo==bar) << endl;  // false (0110==0011为false)
cout << (foo!=bar) << endl;  // true (0110!=0011为true)

cout << (foo&bar) << endl;  // 0010 (按位与，不赋值)
cout << (foo|bar) << endl;  // 0111 (按位或，不赋值)
cout << (foo^bar) << endl;  // 0101 (按位异或，不赋值)

// 访问或赋值
bitset<4> foo ("1011");
    
cout << foo[0] << endl;  //1
cout << foo[1] << endl;  //1
cout << foo[2] << endl;  //0

// 函数（1）
// test函数会对下标越界作出检查
// 而通过 [ ] 访问元素却不会经过下标检查
// 所以，在两种方式通用的情况下，选择test函数更安全一些
bitset<8> foo ("10011011");

cout << foo.count() << endl;  // 5 （count函数用来求bitset中1的位数，foo中共有 5 个 1 
cout << foo.size() << endl;  // 8 （size函数用来求bitset的大小，一共有 8 位

cout << foo.test(0) << endl;  // true test函数用来查下标处的元素是 0 还是 1 ，并返回false或true，此处foo[0]为 1 ，返回true
cout << foo.test(2) << endl;  // false （同理，foo[2]为 0 ，返回false

cout << foo.any() << endl;  // true （any函数检查bitset中是否有 1 
cout << foo.none() << endl;  // false （none函数检查bitset中是否没有 1 
cout << foo.all() << endl;  // false （all函数检查bitset中是全部为 1 

// 函数（2）
bitset<8> foo ("10011011");

cout << foo.flip(2) << endl;  // 10011111 （ flip 函数传参数时，用于将参数位取反，本行代码将 foo 下标 2 处"反转"，即 0 变 1 ， 1 变 0 
cout << foo.flip() << endl;  // 01100000 （ flip 函数不指定参数时，将 bitset 每一位全部取反

cout << foo.set() << endl;  // 11111111 （ set 函数不指定参数时，将 bitset 的每一位全部置为 1
cout << foo.set(3,0) << endl;  // 11110111 （ set 函数指定两位参数时，将第一参数位的元素置为第二参数的值，本行对 foo 的操作相当于 foo[3]=0
cout << foo.set(3) << endl;  // 11111111 （ set 函数只有一个参数时，将参数下标处置为 1 

cout << foo.reset(4) << endl;  // 11101111 （ reset 函数传一个参数时将参数下标处置为 0 
cout << foo.reset() << endl;  // 00000000 （ reset 函数不传参数时将 bitset 的每一位全部置为 0 

// 函数（3）
bitset<8> foo ("10011011");

string s = foo.to_string();  // 将 bitset 转换成 string 类型
unsigned long a = foo.to_ulong();  // 将 bitset 转换成 unsigned long 类型
unsigned long long b = foo.to_ullong();  // 将 bitset 转换成 unsigned long long 类型

cout << s << endl;  // 10011011
cout << a << endl;  // 155
cout << b << endl;  // 155
