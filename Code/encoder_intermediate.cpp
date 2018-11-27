#include <bits/stdc++.h>

using namespace std;

int main(){
	int listen, packets_received=0, m, number_of_packets;
	int temp;
	vector<vector<int> > packet_matrix, encoding_vector;
	cout << "Number of Packets" << endl;
	cin >> number_of_packets;
	cout << "I am listening..." << endl;
	while(1){
		cout << "Should I listen?" << endl;
		cin >> listen;
		if(listen==0){
			break;
		}
		vector<int> temp_data;
		for(int i=0; i<number_of_packets; i++){
			cin >> temp;
			temp_data.push_back(temp);
		}
		cin >> temp;
		temp_data.push_back(temp);
		packet_matrix.push_back(temp_data);
		packets_received++;
	}
	cout << "Packets Received: " << packets_received << endl;
	cout << "Number of Outgoing Edges" << endl;
	cin >> m;
	for(int i=0; i<m; i++){
		vector<int> temp_encoder;
		for(int j=0; j<packets_received; j++){
			cin >> temp;
			temp_encoder.push_back(temp);
			// temp_encoder.push_back(rand()%2);
		}
		encoding_vector.push_back(temp_encoder);
	}
	vector<vector<int> > modified_packet_matrix(m, (vector<int> (number_of_packets, 0)));
	for(int i=0; i<m; i++){
		for(int j=0; j<number_of_packets+1; j++){
			for(int k=0; k<packets_received; k++){
				modified_packet_matrix[i][j]+=encoding_vector[i][k]*packet_matrix[k][j];
				if(j!=number_of_packets){
					modified_packet_matrix[i][j]%=2;
				}
			}
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<number_of_packets+1; j++){
			cout << modified_packet_matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}