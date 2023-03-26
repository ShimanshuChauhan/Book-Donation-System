#define Color_Red "\x1b[31m"
#define Color_Green "\x1b[32m"
#define Color_Yellow "\x1b[33m"
#define Color_Cyan "\x1b[36m"
#define Color_Magenta "\x1b[35m"
#define Color_End "\x1b[0m"

#define printError(X) printf("%s%s%s", Color_Red, X, Color_End)
#define printSuccess(X) printf("%s%s%s", Color_Green, X, Color_End)
#define printInfo(X) printf("%s%s%s", Color_Yellow, X, Color_End)

#define printHeading(X) printf("\n%s                ############ %s ############%s\n", Color_Cyan, X, Color_End)
#define printSubHeading(X) printf("\n%s                         xxxxxxx %s xxxxxxx%s\n", Color_Magenta, X, Color_End)