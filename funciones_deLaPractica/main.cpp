#include <iostream>

using namespace std;

void imprimirDigitos(int n)//SOLO CUANDO VA A IMPRIMIR SE PONE VOID PUES NO RETORNA NADA
{
    int n_1 = n/10000;
    int n_2 = n-(n_1*10000);
    int n_3 = n_2- ((n_2/1000)*1000);
    int n_4 = n_3 - ((n_3/100)*100);
    int n_5 = n_4 - ((n_4/10)*10);
    cout<<n_1<<'\t'<<(n_2/1000)<< '\t'<< (n_3/100) <<'\t'<< (n_4/10)<< '\t'<< n_5 << endl;
}

int numero_deDigitos(int number)//SOLO SE PONE INT CUANDO VA A RETORNAR UN ENTERO
{
    int i;
    for (i=0; number>1; number=number/10)
    {
        i=i+1;
    }
    return i;
}

bool palindrome(int a)//SOLO SE PONE BOOL CUANDO VA A RETORNAR UN BOOLEANO
{
    int primer_digito=a/10000;
    int a_1=a-(primer_digito*10000);
    int segundo_digito=a_1/1000;
    int a_2=a_1-(segundo_digito*1000);
    int tercer_digito=a_2/100;
    int a_3=a_2-(tercer_digito*100);
    int cuarto_digito=a_3/10;
    int a_4=a_3-(cuarto_digito*10);
    int quinto_digito=a_4;

    if (primer_digito == quinto_digito && segundo_digito == cuarto_digito)
        {
            return true;
        }
    else
        {
            return false;
        }
}

int fibonacci(int n)
{
    long long siguiente=1;
    long long subsiguiente=1;
    int fibo;
    n=n-2;
    while(n>0)
    {
        fibo = siguiente + subsiguiente;
        long long subsiguiente_guardado = subsiguiente;
        subsiguiente = siguiente + subsiguiente;
        siguiente = subsiguiente_guardado;
        n = n-1;

    }

    return fibo;
}

bool caracterNumero(int numero)
{
    int p = static_cast<int>(numero);
    if (p >= 48 && p <=57)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void caracterMayuscula(char caracter)
{
    int m = static_cast<int>(caracter);
    if ( m >=65 && m <= 90)
    {
        cout << caracter << " es una letra mayuscula" << endl;
        m=m+32;
        cout << "y su minuscula es  "<< static_cast<char>(m) << endl;
    }
    else if ( m>=97 && m <= 122)
    {
        cout << caracter << " es una letra minuscula" << endl;
        m=m-32;
        cout <<"y su mayuscula es  "<<  static_cast<char>(m) << endl;
    }
}

int main()
{
    //1
    cout<<"coloque un númerode 5 digitos" << endl;
    int n;
    cin >> n;
    if (n-10000>=0 && 100000-n>0)
    {
        imprimirDigitos(n);
    }
    else
    {
        cout<<"no colocó un número de 5 digitos"<<endl;
    }

    //2
    cout <<"coloque un número"<< endl;
    int number;
    cin >> number;
    if (number == 1)
    {
        cout<<"hay 1 digito"<< endl;
    }
    else
    {
        int i= numero_deDigitos(number);
        cout<<"hay "<<i<<" digitos"<<endl;
    }



    //3
    cout<<"coloque un palindrome de 5 digitos"<<endl;
    int a;
    cin >> a;
    if (a-10000>=0 && 100000-a>0)
    {
        palindrome(a);
        if (palindrome(a)==true)
        {
            cout<<a<<" es un numero palindrome"<<endl;
        }
        else if (palindrome(a)==false)
        {
            cout<< a << " no es un numero palindrome"<<endl;
        }
    }
    else
    {
        cout<<"no es un numero de 5 digitos"<< endl;
    }


    //4
    cout<<"coloque la posicion del número de fibonacci que quiere:  ";
    int lugar;
    cin >> lugar;
    int fibo;
    if (lugar>2)
    {
        fibo=fibonacci(lugar);
        cout<<"el numero es "<<fibo<<endl;
    }
    else if (lugar<=2 && lugar >0)
    {
        cout<<"el numero es 1"<<endl;
    }
    else
    {
        cout<< "quien sabe" << endl;
    }


    //5
    cout<<"coloque un caracter de numero:  ";
    char numero;
    cin >> numero;
    bool boleano=caracterNumero(numero);
    if (boleano==true)
    {
        cout << numero << " es un número" << endl;
    }
    else
    {
        cout << numero << " no es un número" << endl;
    }
    cout << "coloque un caracter letra(mayuscula o minuscula):  ";


    //6
    char caracter;
    cin >> caracter;
    caracterMayuscula(caracter);

    return 0;

}
