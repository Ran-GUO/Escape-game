
#g++ vue.cpp  vue2.cpp vue3.cpp modele1.cpp modele2.cpp modele3.cpp controleur1.cpp controleur2.cpp controleur3.cpp myMysql.cpp main.cpp -o main  $(pkg-config gtkmm-3.0 --cflags --libs) -I/usr/include/cppconn -lmysqlcppconn)

main: main.o vue.o vue2.o vue3.o modele1.o modele2.o modele3.o controleur1.o controleur2.o controleur3.o myMysql.o
	g++ main.o vue.o vue2.o vue3.o modele1.o modele2.o modele3.o controleur1.o controleur2.o controleur3.o myMysql.o -o main  -I/usr/include/cppconn -lmysqlcppconn `pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp controleur.hpp vue.hpp windowPlayer.hpp myMysql.hpp player.hpp choixPlayer.hpp
	g++ -c main.cpp -I/usr/include/cppconn -lmysqlcppconn `pkg-config gtkmm-3.0 --cflags --libs`

vue.o vue2.o vue3.o: vue.cpp vue2.cpp vue3.cpp vue.hpp controleur.hpp
	g++ -c vue.cpp `pkg-config gtkmm-3.0 --cflags --libs`
	g++ -c vue2.cpp `pkg-config gtkmm-3.0 --cflags --libs` 
	g++ -c vue3.cpp `pkg-config gtkmm-3.0 --cflags --libs`

modele1.o: modele1.cpp modele.hpp
	g++ -c modele1.cpp `pkg-config gtkmm-3.0 --cflags --libs)` -I/usr/include/cppconn -lmysqlcppconn

modele2.o: modele2.cpp modele.hpp
	g++ -c modele2.cpp `pkg-config gtkmm-3.0 --cflags --libs` -I/usr/include/cppconn -lmysqlcppconn

modele3.o: modele3.cpp modele.hpp
	g++ -c modele3.cpp `pkg-config gtkmm-3.0 --cflags --libs` -I/usr/include/cppconn -lmysqlcppconn

controleur1.o: controleur1.cpp controleur.hpp
	g++ -c controleur1.cpp `pkg-config gtkmm-3.0 --cflags --libs` -I/usr/include/cppconn -lmysqlcppconn

controleur2.o: controleur2.cpp controleur.hpp
	g++ -c controleur2.cpp `pkg-config gtkmm-3.0 --cflags --libs` -I/usr/include/cppconn -lmysqlcppconn 

controleur3.o: controleur3.cpp controleur.hpp
	g++ -c controleur3.cpp `pkg-config gtkmm-3.0 --cflags --libs` -I/usr/include/cppconn -lmysqlcppconn

myMysql.o: myMysql.cpp myMysql.hpp
	g++ -c myMysql.cpp `pkg-config gtkmm-3.0 --cflags --libs` -I/usr/include/cppconn -lmysqlcppconn

clean :
	rm *.o
