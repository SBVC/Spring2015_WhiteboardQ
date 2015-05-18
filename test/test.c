#include <stdio.h>
#include <sqlite3.h>

int main() {
  sqlite3 *connection;
  sqlite3_stmt *result;
  int error = 0;
  int received_count = 0;
  const char *errorMessage; // What is this used for?
  const char *tail;  //tail of what?

  error = sqlite3_open("test.sl3", &connection);
  if (error) {
    puts("Database could not be opened.");
    return 0;
  }

  error = sqlite3_exec(connection, "update people set phonenumber=\'5055559999\' where id=3", 0, 0, 0);

  error = sqlite3_prepare_v2(connection, "select lastname,firstname,phonenumber,id from people order by 1000", &result, &tail);

  if (error != SQLITE_OK) {
    puts("No data!");
    return 0;
  }

  puts("=== === ===");

  /*while (sqlite3_step(result) == SQLITE_ROW) {
    printf("%s|", sqlite_column_text(result, 0));
    printf("%s|", sqlite_column_text(result, 1));
    printf("%s|", sqlite_column_text(result, 2));
    printf("%s|", sqlite_column_int(result, 3));

    received_count++;
  }*/

  puts("=== === ===");
  printf("%d records printed.\n", received_count);

  sqlite3_finalize(result);
  sqlite3_close(connection);

  return 0;
}
