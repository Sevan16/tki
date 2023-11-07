#include <stdio.h>
#include <math.h>
int istriangle(float a, float b, float c);
float gip(float a, float b, float c);
float Pifagor(float a, float b, float c, float g);

int main()
{
    int tr, prtr;
    float a, b, c, g;
    printf("Enter the number of a: ");
    scanf("%f", &a);
    printf("Enter the number of b: ");
    scanf("%f", &b);
    printf("Enter the number of c: ");
    scanf("%f", &c);
    tr = istriangle(a, b, c);
    switch (tr)
    {
        case 1:
        g = gip(a,b,c);
        prtr = Pifagor(a,b,c,g);
        if (prtr == 1)
        {
        printf("Треугольник является прямоугольным\n");
        printf("Гипотенузой является сторона: ");
        printf("%f", g);
        }
        else
        printf("Треугольник не является прямоугольным");
        break;
        
        case 0:
        printf("Треугольника нет");
        break;
        
        default:
        break;
    }
    return 0;
}
float gip(float a, float b, float c)
{
float gip;
if (a > b)
{
    gip = a;
    if (c > gip)
        {
            gip = c;
        }
}
else
{
    gip = b;
    if (c > gip)
    {
        gip = c;
    }
}
return gip;
}
float Pifagor(float a, float b, float c, float g)
{
    if (g == a)
    {
        if(pow(a,2) == pow(b,2) + pow(c, 2))
        return 1;
        else
        return 0;
    }
    
    else if (g == b)
    {
        if(pow(b,2) == pow(a,2) + pow(c, 2))
        return 1;
        else
        return 0;
    }
    
    else if (g == c)
    {
        if(pow(c,2) == pow(a,2) + pow(b, 2))
        return 1;
        else
        return 0;
    }
    
}
int istriangle(float a, float b, float c)
{
   if ((a > b + c) || (b > a + c) || (c > a + b))
   {
       return 0;
   }
   return 1;
}
