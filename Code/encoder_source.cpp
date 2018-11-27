#include <bits/stdc++.h>

using namespace std;

int main(){
	int packet_size, s=1, number_of_packets, m;
	int temp;
	vector<int> data_vector;
	vector<vector<int> > encoding_vector;
	cout << "Size of the Packet to be sent" << endl;
	cin >> packet_size;
	cout << "Data Vector" << endl;
	number_of_packets=packet_size/s;
	for(int i=0; i<number_of_packets; i++){
		cin >> temp;
		data_vector.push_back(temp);
	}
	srand(time(NULL));
	cout << "Number of Outgoing Edges" << endl;
	cin >> m;
	for(int i=0; i<m; i++){
		vector<int> temp_encoder;
		for(int j=0; j<number_of_packets; j++){
			cin >> temp;
			temp_encoder.push_back(temp);
			// temp_encoder.push_back(rand()%2);
		}
		encoding_vector.push_back(temp_encoder);
	}
	cout << "I am sending..." << endl;
	for(int i=0; i<m; i++){
		int res=0;
		for(int j=0; j<number_of_packets; j++){
			res=res^(encoding_vector[i][j]*data_vector[j]);
		}
		encoding_vector[i].push_back(res);
		cout << "Packet #" << i << ": " << res << endl;
	}
	cout << "Vector to be sent" << endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<number_of_packets+1; j++){
			cout << encoding_vector[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}