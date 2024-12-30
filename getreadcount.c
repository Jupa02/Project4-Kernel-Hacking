// test code from https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-xv6
#include "types.h"
#include "stat.h"
#include "user.h"
int test2(void);
int
main(void) {
  int x1 = getreadcount();
  int x2 = getreadcount();
  char buf[100];
  (void) read(4, buf, 1);
  int x3 = getreadcount();
  int i;
  for (i = 0; i < 1000; i++) {
    (void) read(4, buf, 1);
  }
  int x4 = getreadcount();
  printf(1, "XV6_TEST_OUTPUT %d %d %d\n", x2-x1, x3-x2, x4-x3);
  test2();
  exit();
}
int
test2(void) {
  int x1 = getreadcount();

  int rc = fork();

  int total = 0;
  int i;
  for (i = 0; i < 100000; i++) {
    char buf[100];
    (void) read(4, buf, 1);
  }
  // https://wiki.osdev.org/Shutdown
  // (void) shutdown();

  if (rc > 0) {
    (void) wait();
    int x2 = getreadcount();
    total += (x2 - x1);
    printf(1, "XV6_TEST_OUTPUT %d\n", total);
  }
  return(0);
}
