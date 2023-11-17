#include <fstream>
#define MAX_TABURETE 10000
#define TIPURI_TABURETE 7
#define NR_PLACI 6
using namespace std;
int nrTaburete, nrTabureteDiferite, nrMaxTabureteDeAcelasiFel;
int nrTabureteTip[TIPURI_TABURETE];
void citesteDateleDeIntrare();
void calculeazaNrTaburete();
void afiseazaDateleDeIesire();
int main()
{
	citesteDateleDeIntrare();
	calculeazaNrTaburete();
	afiseazaDateleDeIesire();
	return 0;
}

void calculeazaNrTaburete()
{
	nrMaxTabureteDeAcelasiFel = nrTabureteDiferite = 0;
	for (int i = 0; i < TIPURI_TABURETE; i++)
	{
		if (nrTabureteTip[i])
			nrTabureteDiferite++;
		if (nrTabureteTip[i] > nrMaxTabureteDeAcelasiFel)
			nrMaxTabureteDeAcelasiFel = nrTabureteTip[i];
	}
}
bool douaPlaciOpuseSuntRosii(int placa[])
{
	if (placa[0] && placa[5])
		return 1;
	if (placa[1] && placa[3])
		return 1;
	if (placa[2] && placa[4])
		return 1;
	return 0;
}
bool placileCuColtComunSuntRosii(int placa[])
{
	int nrTripleti = 8;
	int triplet[][3] = {
		{0, 1, 2},
		{0, 1, 4},
		{0, 2, 3},
		{0, 3, 4},
		{1, 2, 5},
		{1, 4, 5},
		{2, 3, 5},
		{3, 4, 5}
	};
	for (int i = 0; i < nrTripleti; i++)
		if (placa[triplet[i][0]]
		    && placa[triplet[i][1]]
		    && placa[triplet[i][2]])
			return 1;
	return 0;
}
bool patruPlaciOpuseSuntRosii(int placa[])
{
	if (placa[0] && placa[5] && placa[1] && placa[3])
		return 1;
	if (placa[0] && placa[5] && placa[2] && placa[4])
		return 1;
	if (placa[1] && placa[3] && placa[2] && placa[4])
		return 1;
	return 0;
}
void verificaTipulTaburetelui(int placa[], int nrPlaciRosii)
{
	switch (nrPlaciRosii)
	{
		case 1:
			nrTabureteTip[0]++;
			break;
		case 2:
			if (douaPlaciOpuseSuntRosii(placa))
				nrTabureteTip[1]++;
			else
				nrTabureteTip[2]++;
			break;
		case 3:
			if (placileCuColtComunSuntRosii(placa))
				nrTabureteTip[3]++;
			else
				nrTabureteTip[4]++;
			break;
		case 4:
			if (patruPlaciOpuseSuntRosii(placa))
				nrTabureteTip[5]++;
			else
				nrTabureteTip[6]++;
			break;
	}
}
void citesteDateleDeIntrare()
{
	ifstream fin("taburet.in");
	fin >> nrTaburete;
	for (int i = 0; i < nrTaburete; i++)
	{
		int placa[NR_PLACI], nrPlaciRosii = 0;
		for (int j = 0; j < NR_PLACI; j++)
		{
			fin >> placa[j];
			if (placa[j])
				nrPlaciRosii++;
		}
		verificaTipulTaburetelui(placa, nrPlaciRosii);
	}
	fin.close();
}
void afiseazaDateleDeIesire()
{
	ofstream fout("taburet.out");
	fout << nrTabureteDiferite;
	fout << '\n' << nrMaxTabureteDeAcelasiFel;
	fout.close();
}

