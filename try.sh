gcc firstEx.c  -o firstEx $(mysql_config --cflags --libs)
sudo ./firstEx
