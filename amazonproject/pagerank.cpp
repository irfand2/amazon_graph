#include "pagerank.h"

std::vector<double> pagerank(Graph& g, unsigned iterations) {
	unsigned size_ = g.size();
	// initialize nx1 solution vector, n = number of vertices in the graph
	std::vector<double> ret(size_);
	for (unsigned i = 0; i < size_; i++) {
		ret[i] = std::rand() * 1.0; // initial values are random
	}
	// normalize the vector
	double norm_ = norm(ret);
	for (unsigned i = 0; i < size_; i++) {
		ret[i] /= norm_;
	}
	std::vector<std::vector<bool>>& adj_matrix = g.getAdjMatrix();
	// initialize nxn matrix for pagerank
	std::vector<std::vector<double>> matrix(size_, std::vector<double>(size_));
	for (unsigned i = 0; i < size_; i++) {
		for (unsigned j = 0; j < size_; j++) {
			if (adj_matrix[i][j]) {
				Vertex v = g.getVertexFromIndex(i);
				// d = 0.85 is the damping constant, 1-d = 0.15
				matrix[j][i] = (0.85 / g.out_degree(v)) + (0.15 / size_);
			}
			else {
				matrix[j][i] = (0.15 / size_);
			}
		}
	}
	unsigned counter = 0;
	// perform power iteration with matrix and ret
	while (counter < iterations) {
		ret = matmul(matrix, ret);
		norm_ = norm(ret);
		// normalize the vector to prevent overflow or floating point issues
		for (unsigned i = 0; i < size_; i++) {
			ret[i] /= norm_;
		}
		++counter;
	}
	return ret;
}

double norm(const std::vector<double>& vec) {
	// take the sum of all doubles in vec
	double sum = 0;
	for (double d : vec) {
		sum += d;
	}
	return sum;
}

std::vector<double> matmul(const std::vector<std::vector<double>>& m, const std::vector<double>& v) {
	// m is assumed to be nxn where n is size of vector v
	unsigned size_ = v.size();
	std::vector<double> ret(size_);
	// loop through each row
	for (unsigned i = 0; i < size_; i++) {
		double sum = 0.0;
		// loop through each column
		for (unsigned j = 0; j < size_; j++) {
			// perform the standard matrix - vector multiplication
			sum += m[i][j] * v[j];
		}
		ret[i] = sum;
	}
	return ret;
}