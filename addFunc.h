/**
 * @file addFunc.h
 * @author linoy roytman & lian buzaglo
 * @brief
 * this header file represent assigment 3
 * @date 2021-12-21
 */
#define TXT 1024
#define WORD 30

/**
 * @brief
 *
 * @param c accept char
 * @return the accepted char gematrical value
 */
int gio(int c);

/**
 * @brief
 *
 * @param text represents text
 * @param start point
 * @param end point
 * @return the sum of the  gematrical value of the chars
 *         in the accepted text in the scoup between the accepted points
 */
int sum2 (char* text, int start, int end);

/**
 * @brief
 * return the reverse of that string
 */
char *strrev(char *str);

/**
 * @brief
 * return the string without the first occurance of the char
 */
void del(char *s,char c);

/**
 * @brief
 * scanning word
 */
char *scanW();


/**
 * @brief
 * scanning text
 */
char *scanT();
