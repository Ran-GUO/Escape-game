# Escape-game

C++ project

## vedio link

https://youtu.be/QOWUUFnBoRo

## MySQL

install mysql
```
sudo apt-get update
sudo apt-get install mysql-server
sudo service mysql start
```

connect
```
/usr/bin/mysql -u root -p
Enter password:
mysql>
```

install connector
```
sudo apt-get update
sudo apt-get install libmysqlcppconn-dev
sudo apt-get install libboost-all-dev
```

compile
```
-I/usr/include/cppconn
-I/usr/local/lib/c++/mysql-connector-c++/include
-lmysqlcppconn
-L/usr/local/lib/c++/mysql-connector-c++/lib -lmysqlcppconn
```

using
```
#include <driver.h>
#include <connection.h>
```

## gtkmm

```
sudo apt install libgtkmm-3.0-dev
```

using
```
#include <gtkmm.h>
```

## MVC structure  (Model-View-Controller) 

## links
```
https://developer.gnome.org/gtkmm-tutorial/stable/
https://dev.mysql.com/doc/connector-cpp/8.0/en/
```
