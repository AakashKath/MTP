#include <bits/stdc++.h>

using namespace std;

void backsub(vector<vector<int> > &packet_matrix, int packets_received){
	vector<int> temp(packets_received);
	for(int i=packets_received-1; i>=0; i--){
		temp[i]=packet_matrix[i][packets_received];
		for(int j=i+1; j<packets_received; j++){
			temp[i]-=packet_matrix[i][j]*temp[j];
		}
		temp[i]/=packet_matrix[i][i];
	}
	cout << "Packets Recovered" << endl;
	for(int i=0; i<packets_received; i++){
		cout << temp[i] << endl;
	}
}

void swap_row(vector<vector<int> > &packet_matrix, int packets_received, int k, int i_max){
	for(int i=0; i<=packets_received; i++){
		int temp=packet_matrix[k][i];
		packet_matrix[k][i]=packet_matrix[i_max][i];
		packet_matrix[i_max][i]=temp;
	}
}

int forward_elimination(vector<vector<int> > &packet_matrix, int packets_received){
	for(int k=0; k<packets_received; k++){
		int i_max=k;
		int v_max=packet_matrix[i_max][k];
		for(int i=k+1; i<packets_received; i++){
			if(abs(packet_matrix[i][k])>v_max){
				v_max=packet_matrix[i][k], i_max=i;
			}
		}
		if(!packet_matrix[k][i_max]){
			return k;
		}
		if(i_max!=k){
			swap_row(packet_matrix, packets_received, k, i_max);
		}
		for(int i=k+1; i<packets_received; i++){
			int f=packet_matrix[i][k]/packet_matrix[k][k];
			for(int j=k+1; j<=packets_received; j++){
				packet_matrix[i][j]-=packet_matrix[k][j]*f;
			}
			packet_matrix[i][k]=0;
		}
	}
	return -1;
}

void gaussian(vector<vector<int> > &packet_matrix, int packets_received){
	int singular_flag=forward_elimination(packet_matrix, packets_received);
	if(singular_flag!=-1){
		cout << "Singular Matrix." << endl;
		if(packet_matrix[singular_flag][packets_received]){
			cout << "Inconsistent System." << endl;
		}
		else{
			cout << "May have infinitely many solutions." << endl;
		}
	}
	backsub(packet_matrix, packets_received);
}

int main(){
	int listen, packets_received=0, number_of_packets;
	int temp;
	vector<vector<int> > packet_matrix;
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
	gaussian(packet_matrix, packets_received);
	return 0;
}