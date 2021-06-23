a.out: main.o Buyer.o Seller.o Goods.o functions.o caster.o
	g++ main.o Buyer.o Seller.o Goods.o functions.o caster.o -o a.out

main.o: main.cpp
	g++ -c main.cpp

Student.o: Buyer.cpp Buyer.h
	g++ -c Buyer.cpp

Course.o: Seller.cpp Seller.h
	g++ -c Seller.cpp

Goods.o: Goods.cpp Goods.h
	g++ -c Goods.cpp

functions.o: functions.cpp functions.h
	g++ -c functions.cpp

caster.o: caster.cpp caster.h
	g++ -c caster.cpp

clean:
	rm *.o a.out
