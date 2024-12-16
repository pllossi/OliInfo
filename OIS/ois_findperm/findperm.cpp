// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>

using namespace std;

int main() {
// uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    // SAMPLE INTERACTION, REPLACE WITH YOUR CODE

	cout << 1 << ' ' << 2 << '\n';
	cout.flush();
	int x;
	cin >> x;

    cout << "! "; // print the result
    for (int i = 0; i < N; i++)
		cout << i + 1 << ' ';
	cout << endl;

    return 0;
}
