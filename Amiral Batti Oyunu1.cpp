#include<iostream>
#include<cstring>
#include<cstdlib>
#include<conio.h>


using namespace std;

 string isim1;
 string isim2;

 // 1. oyuncu ve 2. oyuncuların haritalarında 1 olan karelerde gemiler var 0 olan yerler boş veya patlatılmış.

 int harita1[10][10];
 int harita2[10][10];

// 2 karelik gemiler

    int mayinGemisi1[] = { 0,0,0,2 };
    int mayinGemisi2[] = { 0,0,0,2 };

// 3 karelik gemiler
   
    int firkateyn1[] = { 0,0,0,3 };
    int firkateyn2[] = { 0,0,0,3 };

// 3 karelik gemiler
    
    int denizalti1[] = { 0,0,0,3 };
    int denizalti2[] = { 0,0,0,3 };

// 4 karelik gemiler
   
   int kruvazor1[] = { 0,0,0,4 };
   int kruvazor2[] = { 0,0,0,4 };

// 5 karelik gemiler
   
   int ucakGemisi1[] = { 0,0,0,5 };
   int ucakGemisi2[] = { 0,0,0,5 };

// Oyuncudan geminin baslangıc kordinatlarını ve geminin yatay mı dikey mi konumlandıgı bilgisini alalım.

 void GemiGir( int gemi[])
 {
 
    cout<<" Geminin x kordinatini giriniz (0-9) : ";
    cin>>gemi[0];

    cout<<" Geminin y kordinatini giriniz (0-9) : ";
    cin>>gemi[1];

    cout<<" Geminin yonunu giriniz (0:yatay, 1:dikey) : ";
    cin>>gemi[2];
    
}

    // gemiyi haritaya yerlestirme islemi

    void HaritayaGemiYerlestir(int harita[10][10], int gemi[])
    {

    int x = gemi[0];
    int y = gemi[1];
    int yon = gemi[2];
    int uzunluk = gemi[3];

    int i;

    for ( i = 0; i < uzunluk; i++)
    {
        harita[x][y] = 1;

        if (yon == 0) // yatay ise
        {
            y++;
        }
        else // dikey ise
        {
            x++;
        }
        
    }
 }

 // gemileri haritaya yerlestirme islemi

  void HaritaCiz( int harita[10][10] )
  {
      int i,j;

      for ( i = 0; i < 10; i++)

      {
          for ( j = 0; j < 10; j++)

          {
              cout<<harita[i][j]<<" ";
          }

          cout<<endl;

      }
      
  }

  bool HamleYap( string isim , int harita[10][10] )
  {
      int x,y;

      cout<<isim<<" hamle yapiniz (x,y) : ";
      cin>>x>>y;

      if (harita[x][y] == 1) // gemi var
      {

          harita[x][y] = 0;  // gemi vuruldu
          cout<<"Vuruldu"<<endl;
          return true;

      }

      else

      {

          cout<<"Vurulamadi"<<endl;
          return false;
      }
      
  }

  bool OyunBittiMi( int harita[10][10] )
  {
      int i,j;

      for ( i = 0; i < 10; i++)

      {
          for ( j = 0; j < 10; j++)

          {
              if (harita[i][j] == 1) // gemi var
              {
                  return false;
              }
              
          }
          
      }

      return true;
      
  }

  int main()
  
  { 
    
    system("color B");
    cout<<"Amiral Batti Oyununa Hosgeldiniz"<<endl;
    cout<<"Lutfen Kullanim Kilavuzunu Okuyunuz"<<endl;
    cout<<"Kullanim Kilavuzunu Okuduktan Sonra Oyuna Baslamak Icin Bir Tusa Basiniz"<<endl;
    getch();

    cout << "1. oyuncu ismini gir : ";
	cin >> isim1;
	
	GemiGir(mayinGemisi1);
	GemiGir(firkateyn1);
	GemiGir(denizalti1);
	GemiGir(kruvazor1);
	GemiGir(ucakGemisi1);
	HaritayaGemiYerlestir(harita1, mayinGemisi1);
	HaritayaGemiYerlestir(harita1, firkateyn1);
	HaritayaGemiYerlestir(harita1, denizalti1);
	HaritayaGemiYerlestir(harita1, kruvazor1);
	HaritayaGemiYerlestir(harita1, ucakGemisi1);
	HaritaCiz(harita1);
	
	cout << "2. oyuncu ismini gir : ";
	cin >> isim2;
	
	GemiGir(mayinGemisi2);
	GemiGir(firkateyn2);
	GemiGir(denizalti2);
	GemiGir(kruvazor2);
	GemiGir(ucakGemisi2);
	HaritayaGemiYerlestir(harita2, mayinGemisi2);
	HaritayaGemiYerlestir(harita2, firkateyn2);
	HaritayaGemiYerlestir(harita2, denizalti2);
	HaritayaGemiYerlestir(harita2, kruvazor2);
	HaritayaGemiYerlestir(harita2, ucakGemisi2);
	HaritaCiz(harita2);
	
	
    bool oyuncu1VurduMu = true;
    bool oyuncu2VurduMu = true;

    while (true) 
    {
        while (oyuncu1VurduMu == true)
        {
            oyuncu1VurduMu = HamleYap(isim1,harita2);
            if (oyuncu1VurduMu == true )
            {
                HaritaCiz(harita2);
                bool sonuc = OyunBittiMi(harita2);
                if (sonuc == true)
                {
                    cout<<isim1<<" kazandi";
                    system("pause");
                    exit(0);

                }
                
            }
            else
            {
                oyuncu2VurduMu = true;
            }
            
        }

        while (oyuncu2VurduMu)
        {
            oyuncu2VurduMu = HamleYap(isim2,harita1);
            if (oyuncu2VurduMu == true)
            {
                HaritaCiz(harita1);
                bool sonuc = OyunBittiMi(harita1);
                if (sonuc == true)
                {
                    cout<<isim2<<" kazandi";
                    system("pause");
                    exit(0);
                }
                
            }
            else
            {
                oyuncu1VurduMu = true;
            }
            
        }
    
    }

    return 0;

  }
