#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

int main(){
	setlocale(LC_ALL,"Russian");
	cout<<"Programa cozdania grafov\n";

	ofstream DotFile; // Создаем файл для записи
	char Way[16]="Graph.dot";
	DotFile.open(Way, ios_base::trunc);

	cout<<"Kakoy graf boudiet icpolzovatsa ?\n1 - Orientirovani \n2 - Niorientirovani \n";
	string Graph;
	cin>>Graph;

	if (Graph=="1"){
		DotFile<<"digraph G{\n";
	}
	else if (Graph=="2"){
		DotFile<<"graph G{\n";
	}
	cout<<"Vveditie kolitchestva verchin grafa :";
	int V=0;
	cin>>V;
	int Matrix[V+1][V+1];
	for(int i=0;i<V+1;i++){
		for(int l=0;l<V+1;l++){
			Matrix[i][l]=0;
			if(i==0) Matrix[i][l]=l;
			if(l==0) Matrix[i][l]=i;
		}
	}
	cout<<"Dlia vvoda orientirovanih grafov icpolzuite \"->\"\nDlia neorientirovannih \"--\"\nDlia zaverchenia vvoda vveditie\"-0\"\n";
	cout<<"Vveditie zavicimosti grafov, razdelennie nerenocom ctroki:\n";

	SetConsoleCP(1251);
	char Text[100];
	strcpy(Text,"\0");
	string Check="-0\0";
	char c[2];
	int A=0, B=0;
	bool key=false;
	c[1]='\0';
	int R=0;
	c[0]=getchar();
	while (Text!=Check)
	{
		c[0]=getchar();
		while (c[0]!='\n'){
			strcat(Text,c);
			if(isdigit(c[0]) && key==false){
				A=atoi(c);
				key=true;
			}
			else if (isdigit(c[0]) && key==true){
				B=atoi(c);
				if (Matrix[A][B]==0) Matrix[A][B]=1;
				else Matrix[B][A]=1;
				A=B;
			}
			else if(c[0]=='-'){
				R++;
				c[0]=getchar();
				strcat(Text,c);
			}
			c[0]=getchar();
		}
		key=false;
		if (Text!=Check){
			DotFile<<Text<<";\n";
			strcpy(Text,"\0");
		}
		else break;
	}
	R--;

	SetConsoleCP(866);

	for(int i=0;i<V+1;i++){
		cout<<i;
		for(int l=1;l<V+1;l++){
			if (i==0) cout<<" "<<l;
			else{
				cout<<" "<<Matrix[i][l];
			}
		}
		cout<<"\n";
	}
	int Gran=0, k=0;
	bool EndT=false;
	for(int i=1;i<V+1;i++){
		Gran=0;
		for(int l=i;l<V+1;l++){
			if (Matrix[i][l]==1){
				Gran++;
				if(i==l){
                        k++;
					cout<<"Error: obnarujena petla => graf ni yavlaetsa proctim\n";
					EndT=true;

					//printf("boucle trouve entre les noeuds %d et %d\n", i,l);
					printf("%d\n", k);

					break;
				}
				else if(Matrix[i][l]==Matrix[l][i]){

					cout<<"Error: obnarujeni kratnie rebra => graf ni yavlaetsa prictim\n";
					EndT=true;
					break;
				}
			}
		}
		if (Gran==0 && i!=V){
			cout<<"Ochibka: Obnarujen razriv grafa => Graf ni yavlaetsa proctim\n";
			EndT=true;
			break;
		}
		if (EndT==true) break;
	}

	if(EndT==false){
		if (R>=(V-1)*(V-2)/2) cout<<"Danni graf yavlaetsa svazanim.\n";
		else cout<<"Danni graf ni yavlaetsa svazanim.\n";
	}
	else cout<<"Danni graf nivozmojno proverit po teoreme, tak kak on ni yavlaetsa proctim\n";

	DotFile<<"}";
	DotFile.close();

	system("Graphviz\\bin\\gvedit.exe Graph.dot");
}

