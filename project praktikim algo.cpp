#include <iostream>
#include <iomanip>      
#include <string.h>
using namespace std;
typedef struct{
	string maskapai,waktu,tanggal,no,berangkat,tujuan;
	int harga,orang;
}pesawat;
 pesawat data[100];
 void input();
 void search();
 void sorting();
 void sortno();
 void sortmaskapai();
 void sortberangkat();
 void sorttujuan();
 void sortjam();
 void sorttangal();
 void sortharga();
 void search();
 void sercmaskapai();
 void sercberangkat();
 void serctujuan();
 void sercjam();
 void serctanggal();
 void sercharga();
 void rekursif(int a);
 void beli();
 void pointer(int *harga);
 
 
FILE *file;
bool found;
int jumlah,jum;
int n=100;
int main(){
	int pilih;
	char y;
	do
	{
	cout<<"\n\t==================================";
	cout<<"\n\t  MENU :";
	cout<<"\n\t==================================";
	cout<<"\n\t 1.INPUT DATA ( KHUSUS PETUGAS ) ";
	cout<<"\n\t 2.LIST TIKET ";
	cout<<"\n\t 3.CARI TIKET";
	cout<<"\n\t 4.BELI TIKET";
	cout<<"\n\t 5.EXIT ";
	cout<<"\n\t==================================";
	cout<<"\n\t Pilihan = :";cin>>pilih;
	cout<<"\t===================================="<<endl;
	switch (pilih)
	{
		case 1:input();
		break;
		case 2:sorting();
		break;
		case 3:search();
		break;
		case 4:beli();
		break;		
	}
	cout<<"\n\tKEMBALI KE MENU UTAMA (Y/N) = ";cin>>y;	
	} while (y=='y'||y=='Y');
}
void input(){
	file=fopen("file2.txt","w");
	string code;
	cout<<"	\n\n\tMASUKKAN KODE PETUGAS = ";cin>>code;
	if (code=="KODEKU")
	{
		cout<<"\n\tMASUKKAN JUMLAH TIKET\t = ";cin>>jumlah;
	fwrite(&jumlah,sizeof(jumlah),1,file);
	for (int i = 0; i < jumlah; i++)
	{
	cout <<setw(9);rekursif(n);
	cout<<"\n\t\t\t\tSCHADULE PENERBANGAN  "<<endl;
	cout <<setw(9);rekursif(n);
	cout<<"\n\tNO PENERBANGAN\t\t\t= ";cin>>data[i].no;
	cout<<"\tNAMA MASKAPAI\t\t\t= ";cin.ignore(); getline(cin,data[i].maskapai);
	cout<<"\tKOTA/NEGARA KEBERANGKATAN\t= "; getline(cin,data[i].berangkat);
	cout<<"\tKOTA/NEGARA TUNJUAN\t\t= ";getline(cin,data[i].tujuan);
	cout<<"\tJAM PENERBANGAN\t\t\t= "; getline(cin,data[i].waktu);
	cout<<"\tTANGGAL PENERBANGAN(YY-MM-DDD)  = ";cin>>data[i].tanggal;
	cout<<"\tHARGA TIKET\t\t \t= ";cin.ignore(); cin>>data[i].harga;
	cout <<setw(9);rekursif(n);
	fwrite(&data[i],sizeof(data[i]),1,file);
	}	
	}
	else
	cout<<" MAAF KODE YANG ANDA MASUKKAN SALAH ";
	fclose(file);
}
void sorting(){
	file=fopen("file2.txt","r");
	fread(&jumlah,sizeof(jumlah),1,file);
	for (int i = 0; i < jumlah; i++)
	{
		fread(&data[i],sizeof(data[i]),1,file);
		
	}
	int pilih;
	char y;
	do
	{
	cout<<"\n\t\t\tLIST TIKET BERDASARKAN  ";
	cout<<"\n\t1.NO PENERBANGAN ";
	cout<<"\n\t2.NAMA MASKAPAI";
	cout<<"\n\t3.KOTA/NEGARA KEBERANGKATANN";
	cout<<"\n\t4.KOTA/NEGARA TUJUAN ";
	cout<<"\n\t5.JAM PENERBANGAN ";
	cout<<"\n\t6.TANGGAL PENERBANGAN";
	cout<<"\n\t7.HARGA TIKET  ";
	cout<<"\n\t Pilihan = ";cin>>pilih;
	switch (pilih)
	{
		case 1:sortno();
		break;
		case 2:sortmaskapai();
		break;
		case 3:sortberangkat();
		break;
		case 4:sorttujuan();
		break;
		case 5:sortjam();
		break;
		case 6:sorttangal();
		break;
		case 7:sortharga();
		break;			
	}
	cout<<"\n\t\tURUTKAN KEMBALI(Y/N) = ";cin>>y;	
	} while (y=='y'||y=='Y');
	fclose(file);
}
void sortno(){
	pesawat temp;
	for (int i = 0; i < jumlah-1; i++)
	{
		for (int j = 0; j < jumlah-i-1; j++)
		{
			if (data[j].no>data[j+1].no)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
		
	}
	cout <<setw(9);rekursif(n);
	cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
	cout <<setw(9);rekursif(n);
	for (int i = 0; i < jumlah; i++)
	{
		cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	}
	
}
void sortmaskapai(){
	pesawat temp;
	for (int i = 0; i < jumlah-1; i++)
	{
		for (int j = 0; j < jumlah-i-1; j++)
		{
			if (data[j].maskapai>data[j+1].maskapai)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
		
	}
	cout <<setw(9);rekursif(n);
	cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
	cout <<setw(9);rekursif(n);
	for (int i = 0; i < jumlah; i++)
	{
		cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	}
	
}
void sortberangkat(){
	pesawat temp;
	for (int i = 0; i < jumlah-1; i++)
	{
		for (int j = 0; j < jumlah-i-1; j++)
		{
			if (data[j].berangkat>data[j+1].berangkat)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
		
	}
	cout <<setw(9);rekursif(n);
	cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
	cout <<setw(9);rekursif(n);
	for (int i = 0; i < jumlah; i++)
	{
		cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	}
	
}
void sorttujuan(){
	pesawat temp;
	for (int i = 0; i < jumlah-1; i++)
	{
		for (int j = 0; j < jumlah-i-1; j++)
		{
			if (data[j].tujuan>data[j+1].tujuan)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
		
	}
	cout <<setw(9);rekursif(n);
	cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
	cout <<setw(9);rekursif(n);
	for (int i = 0; i < jumlah; i++)
	{
		cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	}
	
}
void sortjam(){
	pesawat temp;
	for (int i = 0; i < jumlah-1; i++)
	{
		for (int j = 0; j < jumlah-i-1; j++)
		{
			if (data[j].waktu>data[j+1].waktu)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
		
	}
	cout <<setw(9);rekursif(n);
	cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
	cout <<setw(9);rekursif(n);
	for (int i = 0; i < jumlah; i++)
	{
		cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	}
	
}
void sorttangal(){
	pesawat temp;
	for (int i = 0; i < jumlah-1; i++)
	{
		for (int j = 0; j < jumlah-i-1; j++)
		{
			if (data[j].tanggal>data[j+1].tanggal)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
		
	}
	cout <<setw(9);rekursif(n);
	cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
	cout <<setw(9);rekursif(n);
	for (int i = 0; i < jumlah; i++)
	{
		cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	}
	
}
void sortharga(){
	pesawat temp;
	for (int i = 0; i < jumlah-1; i++)
	{
		for (int j = 0; j < jumlah-i-1; j++)
		{
			if (data[j].harga>data[j+1].harga)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
		
	}
	cout <<setw(9);rekursif(n);
	cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
	cout <<setw(9);rekursif(n);
	for (int i = 0; i < jumlah; i++)
	{
		cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	}
	
}
void search(){
	file=fopen("file2.txt","r");
	fread(&jumlah,sizeof(jumlah),1,file);
	for (int i = 0; i < jumlah; i++)
	{
		fread(&data[i],sizeof(data[i]),1,file);
	}
	
	int pilih;
	char y;
	do
	{
	cout<<"\n\t\t\tCARI TIKET BERDASARKAN  ";
	cout<<"\n\t1.NAMA MASKAPAI";
	cout<<"\n\t2.KOTA/NEGARA KEBERANGKATANN";
	cout<<"\n\t3.KOTA/NEGARA TUJUAN ";
	cout<<"\n\t4.JAM PENERBANGAN ";
	cout<<"\n\t5.TANGGAL PENERBANGAN";
	cout<<"\n\t6.HARGA TIKET  ";
	cout<<"\n\t Pilihan = ";cin>>pilih;
	switch (pilih)
	{
		case 1:sercmaskapai();
		break;
		case 2:sercberangkat();
		break;
		case 3:serctujuan();
		break;
		case 4:sercjam();
		break;
		case 5:serctanggal();
		break;
		case 6:sercharga();
		break;			
	}
	cout<<"\n\tCARI KEMBALI(Y/N) = ";cin>>y;	
	} while (y=='y'||y=='Y');
	fclose(file);
}
void sercmaskapai(){
string cari;
	
		cout<<"\n\tCARI DATA MAKAPAI = ";cin.ignore();getline(cin,cari);
	
			found=false;
			cout <<setw(9);rekursif(n);
			cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
			cout <<setw(9);rekursif(n);
			for (int i = 0; i < jumlah; i++)
			{
				
				if (cari==data[i].maskapai)
				{
					cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	
				found=true;
				}
				}if(!found)
				cout<<"\t\ttidak ada"<<endl<<endl;
			
	
	
	}
void sercberangkat(){
	string cari;
	cout<<"\n\tCARI DATA KEBERANGKATAN = ";cin.ignore();getline(cin,cari);
	
			found=false;
			cout <<setw(9);rekursif(n);
			cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
			cout <<setw(9);rekursif(n);
			for (int i = 0; i < jumlah; i++)
			{
				
				if (cari==data[i].berangkat)
				{
					cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	
				found=true;
				}
				}if(!found)
				cout<<" \nDATA YANG ANDA CARI TIDAK TERSEDIA \n\tUNTUK SAAT INI\n\t\t TERIMAKASIH";	

}
void serctujuan(){
	string cari;
	cout<<"\n\tCARI DATA TUJUAN = ";cin.ignore();getline(cin,cari);
	found=false;
			cout <<setw(9);rekursif(n);
			cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
			cout <<setw(9);rekursif(n);
			for (int i = 0; i < jumlah; i++)
			{
				
				if (cari==data[i].tujuan)
				{
					cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	
				found=true;
				}
				}if(!found)
				cout<<" \nDATA YANG ANDA CARI TIDAK TERSEDIA \n\tUNTUK SAAT INI\n\t\t TERIMAKASIH";	

}
void sercjam(){
	string cari;
	cout<<"\n\tCARI JAM KEBERANGKATAN = ";cin.ignore();getline(cin,cari);
	found=false;
			cout <<setw(9);rekursif(n);
			cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
			cout <<setw(9);rekursif(n);
			for (int i = 0; i < jumlah; i++)
			{
				
				if (cari==data[i].waktu)
				{
					cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	
				found=true;
				}
				}if(!found)
				cout<<" \nDATA YANG ANDA CARI TIDAK TERSEDIA \n\tUNTUK SAAT INI\n\t\t TERIMAKASIH";	

}
void serctanggal(){
	string cari;
	cout<<"\n\tCARI TANGGAL KEBERANGKATAN = ";cin.ignore();getline(cin,cari);
	found=false;
			cout <<setw(9);rekursif(n);
			cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
			cout <<setw(9);rekursif(n);
			for (int i = 0; i < jumlah; i++)
			{
				
				if (cari==data[i].tanggal)
				{
					cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	
				found=true;
				}
				}if(!found)
				cout<<" \nDATA YANG ANDA CARI TIDAK TERSEDIA \n\tUNTUK SAAT INI\n\t\t TERIMAKASIH";	

}
void sercharga(){
	int cari;
	cout<<"\n\tCARI HARGA = ";cin>>cari;
	found=false;
			cout <<setw(9);rekursif(n);
			cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
			cout <<setw(9);rekursif(n);
			for (int i = 0; i < jumlah; i++)
			{
				
				if (cari==data[i].harga)
				{
					cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	
				found=true;
				}
				}if(!found)
				cout<<" \nDATA YANG ANDA CARI TIDAK TERSEDIA \n\tUNTUK SAAT INI\n\t\t TERIMAKASIH";	

}
void beli(){
	
	file=fopen("file2.txt","r");
	fread(&jumlah,sizeof(jumlah),1,file);
	for (int i = 0; i < jumlah; i++)
	{
		fread(&data[i],sizeof(data[i]),1,file);
		
	}
	string cari,cari1,cari2,cari3,cari4;
	int harga;
	char beli;
	
	cout <<setw(9);rekursif(n);
	cout <<setw(10)<<"\t| NO" << " | " << "  MASKAPAI " << " |" << "  KEBERANGKATAN  " << " | " << "    TUJUAN     "<<"|"<<"    JAM      "<<"|"<<"    TANGGAL    "<<" | "<<"   HARGA   "<<" | \n";
	cout <<setw(9);rekursif(n);
	for (int i = 0; i < jumlah; i++)
	{
		cout <<setw(10)<<" "<<data[i].no<<setw(12)<<data[i].maskapai<<setw(15)<<data[i].berangkat<<setw(18)<<data[i].tujuan<<setw(16)<<data[i].waktu<<setw(16)<<data[i].tanggal<<setw(16)<<data[i].harga<<endl;
	}
	cout<<"\n\t\t\tMENU PEMBELIAN  "<<endl;
	cout <<setw(9);rekursif(n);
	cout<<"\n\t PROMO"<<endl;
	cout<<"\n\t * TOTAL PEMBELIAN > 3JUTA "<<endl;
	cout<<"\n\t   CASH BACK 500000 "<<endl;
	cout <<setw(9);rekursif(n);

	
	cout<<"\n\tJUMLAH TIKET YANG DI BELI = ";cin>>jum;
	cout<<"\tNAMA MASKAPAI\t\t\t= ";cin.ignore();getline(cin,cari);
	cout<<"\tKOTA/NEGARA KEBERANGKATAN\t= ";getline(cin,cari1);
	cout<<"\tKOTA/NEGARA TUNJUAN\t\t= ";getline(cin,cari2);
	cout<<"\tJAM PENERBANGAN\t\t\t= ";getline(cin,cari3);
	cout<<"\tTANGGAL PENERBANGAN(YY-MM-DDD)  = ";getline(cin,cari4);
	for (int i = 0; i < jumlah; i++)
	{
	if (cari == data[i].maskapai && cari1==data[i].berangkat && cari2==data[i].tujuan && cari3==data[i].waktu && cari4==data[i].tanggal)
	{
		harga=data[i].harga*jum;
		pointer(&harga);
		cout<<"\n\t\tHARGA TOTAL  = "<<harga;
		cout<<"\n\t\tBeli ?(Y|N) = ";cin>>beli;
		if (beli=='y'||'Y')
	{	
		cout <<setw(9);rekursif(n);
		cout<<"\n\t\t\t\tPEMBELIAN ANDA BERHASIL \n\t\t\t\t\tTERIMAKASIH"<<endl<<endl;
		cout <<setw(9);rekursif(n);	
	}
	}
		
	}
	
	fclose(file);
}
void pointer(int *harga){
	
	if (*harga>3000000){
	*harga=*harga-500000;
	
	}	
}
void rekursif(int a){
	
	if (a>0){
	cout<<"=";
	rekursif(a-1);
	}
	else
	cout<<"="<<endl;

}
