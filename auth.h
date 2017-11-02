typedef struct passww
{
    char *pw_name;
    char *pw_passwd;
    char *pw_realname;
    struct passww *next;
}passww;

typedef struct List
{
    struct passww *start;
} List ;

void printfHello();

void encryption(char *s_encrypt) ;

void decryption(char *s_decrypt);

void add(List *list,  passww *node) ;

void fromFile(List *list);

void addstring(List *list,char *name,char *pass,char *realName);

passww * getpw(List *list,	char *name,char *pass) ;

void  toFile(List *list);
