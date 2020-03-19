#include <stdio.h>
#include <mysql.h>

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main(int argc, char **argv)
{
    MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        printf( "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "345", "testdb", 0, NULL, 0) == NULL)
    {
        printf( "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);

    }

    if (mysql_query(con, ""))
    {
        printf( "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    mysql_close(con);
    exit(0);
}
