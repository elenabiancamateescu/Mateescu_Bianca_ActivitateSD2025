#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Masina {
	int id;
	int an;
	char* sofer;
	float kmParcursi;
	char initialaProducator;
};

struct Masina initializare(int id, int an, const char* sofer, float kmParcursi, char initialaProducator) {
	struct Masina m;
	m.id = id;
	m.an = an;
	m.sofer = (char*)malloc(strlen(sofer) + 1);
	strcpy_s(m.sofer, strlen(sofer) + 1, sofer);
	m.kmParcursi = kmParcursi;
	m.initialaProducator = initialaProducator;
	return m;
}

void afisare(struct Masina m)
{
	printf("ID: %d\n", m.id);
	printf("An fabricatie: %d\n", m.an);
	printf("Sofer: %s\n", m.sofer);
	printf("KmParcursi: %f\n", m.kmParcursi);
	printf("Initiala: %c\n", m.initialaProducator);
}

void modifica_Atribut(struct Masina* m, const char* nouSofer)
{
	//modificare sofer
	if (strlen(nouSofer) >= 3)
	{
		if (m->sofer != NULL)
		{
			free(m->sofer);
		}
		m->sofer = (char*)malloc(strlen(nouSofer) + 1);
		strcpy_s(m->sofer, strlen(nouSofer) + 1, nouSofer);
	}

}

void dezalocare(struct Masina* m)
{
	if (m->sofer != NULL)
	{
		free(m->sofer);
	}
	m->sofer = NULL;
}

int main()
{
	struct Masina masina;
	masina = initializare(1, 2004, "Ana", 2004.6, 'W');
	afisare(masina);
	modifica_Atribut(&masina, "Bianca");
	afisare(masina);
	dezalocare(&masina);
	afisare(masina);
	return 0;
}