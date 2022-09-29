from time import sleep

def printf(a, *args):
    print(a, end=' ')
    if not args:
        return
    printf(*args)
    sleep(1)

printf(1, 2, 3)