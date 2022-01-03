#include <iostream>
#include <vector>

using namespace std;

//class ZbioryRozlaczne
//{
//public:
//    virtual char* find_set(char* x) = 0;
//    virtual ZbioryRozlaczne make_set(char* x) = 0;
//    virtual void _union(char* x, char* y) = 0;
//    virtual friend ostream& operator<<(ostream& out, const ZbioryRozlaczne& dt) = 0;
//};

class Wezel
{
private:
    Wezel* rodzic;
    char znak;
public:
    Wezel(char z);
    char zwrocZnak();
    Wezel* zwrocRodzic();
    void zmienZnak(char z);
    void zmienRodzic(Wezel* r);
};

class ImplementacjaDrzewa
{
protected:
    vector<Wezel*> wektorWezlow;
public:
    Wezel* find_set(Wezel* x);
    Wezel* make_set(char x);
    void _union(Wezel* x, Wezel* y);
    friend ostream& operator<<(ostream& out, const ImplementacjaDrzewa& zr);
    Wezel* zwrocWezel(int indeks);
    ~ImplementacjaDrzewa();
};

class ID_zKompresjaSciezki : public ImplementacjaDrzewa
{
public:
    Wezel* find_set(Wezel* x);
};


int main()
{
    {
        cout << "Test zbiorow rozlacznych - struktura lasu:" << endl;
        //legenda!
        cout << "legenda:" << endl << "? - reprezentant" << endl;
        cout << "?|# \t ? - element \t # - rodzic elementu \"?\"" << endl << endl;
        ImplementacjaDrzewa zbiory_rozlaczne;
        zbiory_rozlaczne.make_set('x');
        zbiory_rozlaczne.make_set('y');
        zbiory_rozlaczne.make_set('l');
        zbiory_rozlaczne.make_set('c');
        zbiory_rozlaczne.make_set('h');
        zbiory_rozlaczne.make_set('m');
        zbiory_rozlaczne.make_set('t');
        zbiory_rozlaczne.make_set('z');
        cout << endl << "Dodajemy elementy: x, y ,l, c, h, m, t, z" << endl << zbiory_rozlaczne;
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(2), zbiory_rozlaczne.zwrocWezel(1));
        cout << endl << "union(zbiory_rozlaczne.zwrocWezel(2),zbiory_rozlaczne.zwrocWezel(1)): y do l" << endl << zbiory_rozlaczne;
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(2), zbiory_rozlaczne.zwrocWezel(5));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(4), zbiory_rozlaczne.zwrocWezel(2));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(7), zbiory_rozlaczne.zwrocWezel(6));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(0), zbiory_rozlaczne.zwrocWezel(3));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(5), zbiory_rozlaczne.zwrocWezel(3));
        cout << endl << "polaczenie kilku elementow metoda _union(x, y):" << endl << zbiory_rozlaczne;
        cout << endl << "find_set(zbiory_rozlaczne.zwrocWezel(3)): (wezel c) h  -  ";
        cout << zbiory_rozlaczne.find_set(zbiory_rozlaczne.zwrocWezel(3))->zwrocZnak();
        cout << endl << endl;
    }
    {
        cout << "Test zbiorow rozlacznych - struktura lasu z kompresja sciezki:" << endl;
        //legenda!
        cout << "legenda:" << endl << "? - reprezentant" << endl;
        cout << "?|# \t ? - element \t # - rodzic elementu \"?\"" << endl << endl;
        ID_zKompresjaSciezki zbiory_rozlaczne;
        zbiory_rozlaczne.make_set('x');
        zbiory_rozlaczne.make_set('y');
        zbiory_rozlaczne.make_set('l');
        zbiory_rozlaczne.make_set('c');
        zbiory_rozlaczne.make_set('h');
        zbiory_rozlaczne.make_set('m');
        zbiory_rozlaczne.make_set('t');
        zbiory_rozlaczne.make_set('z');
        zbiory_rozlaczne.make_set('p');
        zbiory_rozlaczne.make_set('q');
        cout << endl << "Dodajemy elementy: x, y ,l, c, h, m, t, z, p, q" << endl << zbiory_rozlaczne;
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(2), zbiory_rozlaczne.zwrocWezel(1));
        cout << endl << "union(zbiory_rozlaczne.zwrocWezel(2),zbiory_rozlaczne.zwrocWezel(1)): y do l" << endl << zbiory_rozlaczne;
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(2), zbiory_rozlaczne.zwrocWezel(5));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(4), zbiory_rozlaczne.zwrocWezel(2));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(7), zbiory_rozlaczne.zwrocWezel(6));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(0), zbiory_rozlaczne.zwrocWezel(3));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(5), zbiory_rozlaczne.zwrocWezel(3));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(9), zbiory_rozlaczne.zwrocWezel(0));
        zbiory_rozlaczne._union(zbiory_rozlaczne.zwrocWezel(8), zbiory_rozlaczne.zwrocWezel(9));
        cout << endl << "polaczenie kilku elementow metoda _union(x, y):" << endl << zbiory_rozlaczne;
        cout << endl << "find_set(zbiory_rozlaczne.zwrocWezel(4)): (wezel h) p  -  ";
        cout << zbiory_rozlaczne.find_set(zbiory_rozlaczne.zwrocWezel(4))->zwrocZnak();
        cout << endl << zbiory_rozlaczne;
        cout << endl << "find_set(zbiory_rozlaczne.zwrocWezel(1)): (wezel y) p  -  ";
        cout << zbiory_rozlaczne.find_set(zbiory_rozlaczne.zwrocWezel(1))->zwrocZnak();
        cout << endl << zbiory_rozlaczne;
        cout << endl << endl;
    }

    return 0;
}



Wezel::Wezel(char z)
{
    znak = z;
}

char Wezel::zwrocZnak()
{
    return znak;
}

Wezel* Wezel::zwrocRodzic()
{
    return rodzic;
}

void Wezel::zmienZnak(char z)
{
    znak = z;
}

void Wezel::zmienRodzic(Wezel* r)
{
    rodzic = r;
}

Wezel* ImplementacjaDrzewa::find_set(Wezel* x)
{
    if (x->zwrocRodzic() == nullptr || x == nullptr)
        return nullptr;
    Wezel* temp = x->zwrocRodzic();
    while (x != temp)
    {
        x = temp;
        temp = x->zwrocRodzic();
    }
    return x;
}

Wezel* ImplementacjaDrzewa::make_set(char x)
{
    Wezel* nowy = new Wezel(x);
    nowy->zmienRodzic(nowy);
    wektorWezlow.push_back(nowy);
    return nowy;
}

void ImplementacjaDrzewa::_union(Wezel* x, Wezel* y)
{
    Wezel* rodzicX = find_set(x);
    Wezel* rodzicY = find_set(y);
    rodzicY->zmienRodzic(rodzicX);
}

Wezel* ImplementacjaDrzewa::zwrocWezel(int indeks)
{
    if (indeks < wektorWezlow.size())
        return wektorWezlow[indeks];
    else
        return nullptr;
}

ImplementacjaDrzewa::~ImplementacjaDrzewa()
{
    for (int i = 0; i < wektorWezlow.size(); i++)
    {
        delete wektorWezlow[i];
    }
}

ostream& operator<<(ostream& out, const ImplementacjaDrzewa& zr)
{
    vector<Wezel*> znalezione;  //wektor znalezionych
    vector<Wezel*> pomocnicze = zr.wektorWezlow;    //zmniejszaj¹cy siê wektor wezlow
    for (int i = 0; i < pomocnicze.size(); i++)     //wypisanie reprezentantow
    {
        if (pomocnicze[i]->zwrocRodzic() == pomocnicze[i])      //czy jest reprezentantem
        {
            out << pomocnicze[i]->zwrocZnak() << "  ";
            znalezione.push_back(pomocnicze[i]);
            swap(pomocnicze[i], pomocnicze.back());
            pomocnicze.pop_back();
            i--;
        }
    }
    out << endl;
    while (!pomocnicze.empty())
    {
        int rozmiarWektora = znalezione.size();
        for (int i = 0; i < rozmiarWektora; i++)
        {
            for (int j = 0; j < pomocnicze.size(); j++)
            {
                if (pomocnicze[j]->zwrocRodzic() == znalezione[i])
                {
                    out << pomocnicze[j]->zwrocZnak() << "|" << znalezione[i]->zwrocZnak() << "  ";
                    znalezione.push_back(pomocnicze[j]);
                    swap(pomocnicze[j], pomocnicze.back());
                    pomocnicze.pop_back();
                    j--;
                }
                if (pomocnicze.empty())
                    break;
            }
            swap(znalezione[i], znalezione.back());
            if (znalezione.size() <= rozmiarWektora)    //jesli wektor nie zostanie powiekszony
            {
                i--;
                rozmiarWektora--;
            }
            znalezione.pop_back();
            if (pomocnicze.empty())
                break;
        }
        out << endl;
    }
    return out;
}

Wezel* ID_zKompresjaSciezki::find_set(Wezel* x)
{
    if (x->zwrocRodzic() == nullptr || x == nullptr)
        return nullptr;
    Wezel* temp = x->zwrocRodzic();
    Wezel* y = x;
    while (y != temp)
    {
        y = temp;
        temp = y->zwrocRodzic();
    }
    while (x != y)
    {
        temp = x;
        x = x->zwrocRodzic();
        temp->zmienRodzic(y);
    }
    return y;
}
