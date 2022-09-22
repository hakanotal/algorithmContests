g++ -std=c++11 pro.cpp -o pro
echo 'code compiled'
./pro < in/a.txt > out/a.out.txt
echo 'a.txt is done'
./pro < in/b.txt > out/b.out.txt
echo 'b.txt is done'
./pro < in/c.txt > out/c.out.txt
echo 'c.txt is done'
./pro < in/d.txt > out/d.out.txt
echo 'd.txt is done'
./pro < in/e.txt > out/e.out.txt
echo 'e.txt is done'