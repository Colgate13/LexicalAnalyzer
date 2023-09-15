#include <stdio.h>
#include <stdlib.h>
#include "../includes/Error.h"

void throwError(int code, char *message)
{
  Error Error = {
    .code = code,
    .message = message
  };

  printf("> Error: %d with message: %s\n", Error.code, Error.message);
  exit(Error.code);
}
