#include <fstream>
#include <iostream>
#include<cmath>
using namespace std;
int main() {
	//sprint 1
	char* header; header = new char[12];
	int* n; n = (int*)header; *n = 500;
	float* f; f = (float*)(header + 4); *f = 1000;
	short* a; a = (short*)(header + 8); *a = 10000;
	short* p; p = (short*)(header + 10); *p = 12;

	ofstream xx("a.dat", ios::binary | ios::out);
	if (!xx) return 666;
	xx.write(header, 12 * sizeof(char));
	xx.close();


	// sprint 2
	ifstream aa("a.dat", ios::binary | ios::in);
	if (!aa) return 666;
	aa.read(header, 12 * sizeof(char));
	aa.close();
	cout << "  f" << *f << endl;

	*f = 700;

	ofstream yy("b.dat", ios::binary | ios::out);
	if (!yy) return 666;
	yy.write(header, 12 * sizeof(char));
	yy.close();

	ifstream bb("b.dat", ios::binary | ios::in);
	if (!bb) return 666;
	bb.read(header, 12 * sizeof(char));
	bb.close();
	cout << "  f" << *f << endl;


	//sprint 3

	*f = 1000;

	short* data; data = new short[*n];
	const float pi = 3.141592;
	float dt = 1. / f[0] / 20.0;
	for (int i = 0; i < n[0]; i++)
		data[i] = short(a[0] * sin(2.0 * pi * f[0] * i * dt));

	ofstream ww("a.dat", ios::binary | ios::out);
	if (!ww) return 666;
	ww.write(header, 12 * sizeof(char));
	ww.write((char*)data, n[0] * sizeof(short));
	ww.close();



	*f = 700;

	short* datab; datab = new short[*n];
	for (int i = 0; i < n[0]; i++)
		datab[i] = short(a[0] * sin(2.0 * pi * f[0] * i * dt));

	ofstream rr("b.dat", ios::binary | ios::out);
	if (!rr) return 666;
	rr.write(header, 12 * sizeof(char));
	rr.write((char*)datab, n[0] * sizeof(short));
	rr.close();



	//sprint 4

	short* data1; data1 = new short[*n];
	short* data2; data2 = new short[*n];

	ifstream qq("a.dat", ios:: binary | ios:: in);
	qq.read(header, 12);
	qq.read((char*)data1, n[0] * sizeof(short));

	ifstream gg("b.dat", ios::binary | ios::in);
	gg.read(header, 12);
	gg.read((char*)data2, n[0] * sizeof(short));


	ofstream vv("c.txt");
	if (!vv) return 666;
	for (int i = 0; i < n[0]; i++)
		vv << i * dt << " " << data1[i] << " " << data2[i] << endl;
	vv.close();
}