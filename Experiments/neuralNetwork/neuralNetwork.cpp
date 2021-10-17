//
//  main.cpp
//  NeuralNetwork
//
//  Created by Santiago Becerra on 9/15/19.
//  Copyright © 2019 Santiago Becerra. All rights reserved.
//
//

#include <iostream>
#include <list>
#include <cstdlib>
#include <math.h>

// Simple network that can learn XOR
// Feartures : sigmoid activation function, stochastic gradient descent, and mean square error fuction

// Potential improvements :
// Different activation functions
// Batch training
// Different error funnctions
// Arbitrary number of hidden layers
// Read training end test data from a file
// Add visualization of training
// Add recurrence? (maybe that should be a separate project)

double sigmoid(double x) { return 1 / (1 + exp(-x)); }
double dSigmoid(double x) { return x * (1 - x); }
double init_weight() { return ((double)rand())/((double)RAND_MAX); }

void shuffle(int *array, size_t n){
    if (n > 1){
        size_t i;
        for (i = 0; i < n - 1; i++){
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main(int argc, const char * argv[]) {

    static const int numInputs = 2;
    static const int numHiddenNodes1 = 2;
    static const int numHiddenNodes2 = 2;
    static const int numOutputs = 1;
    
    const double lr = 0.1f;
    
    double hiddenLayer1[numHiddenNodes1];
    double hiddenLayer2[numHiddenNodes2];
    double outputLayer[numOutputs];
    
    double hiddenLayerBias1[numHiddenNodes1];
    double hiddenLayerBias2[numHiddenNodes2];
    double outputLayerBias[numOutputs];

    double hiddenWeights1[numInputs][numHiddenNodes1];
    double hiddenWeights2[numHiddenNodes1][numHiddenNodes2];
    double outputWeights[numHiddenNodes2][numOutputs];
    
    static const int numTrainingSets = 4;
    double training_inputs[numTrainingSets][numInputs] = { {0.0f,0.0f},{1.0f,0.0f},{0.0f,1.0f},{1.0f,1.0f} };
    double training_outputs[numTrainingSets][numOutputs] = { {0.0f},{1.0f},{1.0f},{0.0f} };
    
    for (int i=0; i<numInputs; i++) {
        for (int j=0; j<numHiddenNodes1; j++) {
            hiddenWeights1[i][j] = init_weight();
        }
    }
    for (int i=0; i<numHiddenNodes1; i++) {
        for (int j=0; j<numHiddenNodes2; j++) {
            hiddenWeights2[i][j] = init_weight();
        }
    }
    for (int i=0; i<numHiddenNodes1; i++) {
        hiddenLayerBias1[i] = init_weight();
    }
    for (int i=0; i<numHiddenNodes2; i++) {
        hiddenLayerBias2[i] = init_weight();
        for (int j=0; j<numOutputs; j++) {
            outputWeights[i][j] = init_weight();
        }
    }
    for (int i=0; i<numOutputs; i++) {
        outputLayerBias[i] = init_weight();
    }
    
    int trainingSetOrder[] = {0,1,2,3};
    
    for (int n=0; n < 100000; n++) {
        //shuffle(trainingSetOrder,numTrainingSets);
        for (int x=0; x<numTrainingSets; x++) {
            
            int i = trainingSetOrder[x];
            
            // Forward pass
            
            for (int j=0; j<numHiddenNodes1; j++) {
                double activation=hiddenLayerBias1[j];
                 for (int k=0; k<numInputs; k++) {
                    activation+=training_inputs[i][k]*hiddenWeights1[k][j];
                }
                hiddenLayer1[j] = sigmoid(activation);
            }
            
            for (int j=0; j<numHiddenNodes2; j++) {
                double activation=hiddenLayerBias2[j];
                 for (int k=0; k<numHiddenNodes1; k++) {
                    activation+=training_inputs[i][k]*hiddenWeights2[k][j];
                }
                hiddenLayer2[j] = sigmoid(activation);
            }
            
            for (int j=0; j<numOutputs; j++) {
                double activation=outputLayerBias[j];
                for (int k=0; k<numHiddenNodes2; k++) {
                    activation+=hiddenLayer2[k]*outputWeights[k][j];
                }
                outputLayer[j] = sigmoid(activation);
            }
            
            //std::cout << "Input:" << training_inputs[i][0] << " " << training_inputs[i][1] << "    Output:" << outputLayer[0] << "    Expected Output: " << training_outputs[i][0] << "\n";
            
           // Backprop
            
            double deltaOutput[numOutputs];
            for (int j=0; j<numOutputs; j++) {
                double errorOutput = (training_outputs[i][j]-outputLayer[j]);
                deltaOutput[j] = errorOutput*dSigmoid(outputLayer[j]);
            }
            
            double deltaHidden2[numHiddenNodes2];
            for (int j=0; j<numHiddenNodes2; j++) {
                double errorHidden = 0.0f;
                for(int k=0; k<numOutputs; k++) {
                    errorHidden+=deltaOutput[k]*outputWeights[j][k];
                }
                deltaHidden2[j] = errorHidden*dSigmoid(hiddenLayer2[j]);
            }
            
            double deltaHidden1[numHiddenNodes1];
            for (int j=0; j<numHiddenNodes1; j++) {
                double errorHidden = 0.0f;
                for(int k=0; k<numHiddenNodes2; k++) {
                    errorHidden+=deltaOutput[k]*hiddenWeights2[j][k];
                }
                deltaHidden1[j] = errorHidden*dSigmoid(hiddenLayer1[j]);
            }
            
            for (int j=0; j<numOutputs; j++) {
                outputLayerBias[j] += deltaOutput[j]*lr;
                for (int k=0; k<numHiddenNodes2; k++) {
                    outputWeights[k][j]+=hiddenLayer2[k]*deltaOutput[j]*lr;
                }
            }
            
            for (int j=0; j<numHiddenNodes2; j++) {
                hiddenLayerBias2[j] += deltaHidden2[j]*lr;
                for(int k=0; k<numInputs; k++) {
                    hiddenWeights2[k][j]+=training_inputs[i][k]*deltaHidden2[j]*lr;
                }
            }
            
            for (int j=0; j<numHiddenNodes1; j++) {
                hiddenLayerBias1[j] += deltaHidden1[j]*lr;
                for(int k=0; k<numHiddenNodes2; k++) {
                    hiddenWeights1[k][j]+=training_inputs[i][k]*deltaHidden1[j]*lr;
                }
            }
        }
    }
    
    // Print weights
    
    std::cout << "Layer 1\n";
    std::cout << "Final Hidden Weights [ ";
    for (int j=0; j<numHiddenNodes1; j++) {
        std::cout << "[ ";
        for(int k=0; k<numInputs; k++) {
            std::cout << hiddenWeights1[k][j] << " ";
        }
        std::cout << "] ";
    }
    std::cout << "]\n";
    
    std::cout << "Final Hidden Biases [ ";
    for (int j=0; j<numHiddenNodes1; j++) {
        std::cout << hiddenLayerBias1[j] << " ";

    }
    std::cout << "]\n";
    
    std::cout << "Layer 2\n";
    
    std::cout << "Final Hidden Weights [ ";
    for (int j=0; j<numHiddenNodes2; j++) {
        std::cout << "[ ";
        for(int k=0; k<numInputs; k++) {
            std::cout << hiddenWeights2[k][j] << " ";
        }
        std::cout << "] ";
    }
    std::cout << "] \n";
     
   
    std::cout << "Final Hidden Biases [ ";
    for (int j=0; j<numHiddenNodes2; j++) {
        std::cout << hiddenLayerBias2[j] << " ";

    }
    std::cout << "]\n";
    std::cout << "Outpud\n";
    std::cout << "Final Output Weights";
    for (int j=0; j<numOutputs; j++) {
        std::cout << "[ ";
        for (int k=0; k<numHiddenNodes2; k++) {
            std::cout << outputWeights[k][j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "Final Output Biases [ ";
    for (int j=0; j<numOutputs; j++) {
        std::cout << outputLayerBias[j] << " ";
        
    }
    std::cout << "]\n";
    
    
    std::cout << "Example of output\n";
    
    
    
    shuffle(trainingSetOrder,numTrainingSets);
        for (int x=0; x<numTrainingSets; x++) {
            
            int i = trainingSetOrder[x];
            
            // Forward pass
            
            for (int j=0; j<numHiddenNodes1; j++) {
                double activation=hiddenLayerBias1[j];
                 for (int k=0; k<numInputs; k++) {
                    activation+=training_inputs[i][k]*hiddenWeights1[k][j];
                }
                hiddenLayer1[j] = sigmoid(activation);
            }
            
            for (int j=0; j<numHiddenNodes2; j++) {
                double activation=hiddenLayerBias2[j];
                 for (int k=0; k<numHiddenNodes1; k++) {
                    activation+=training_inputs[i][k]*hiddenWeights2[k][j];
                }
                hiddenLayer2[j] = sigmoid(activation);
            }
            
            for (int j=0; j<numOutputs; j++) {
                double activation=outputLayerBias[j];
                for (int k=0; k<numHiddenNodes2; k++) {
                    activation+=hiddenLayer2[k]*outputWeights[k][j];
                }
                outputLayer[j] = sigmoid(activation);
            }
            
            std::cout << "Input:" << training_inputs[i][0] << " " << training_inputs[i][1] << "    Output:" << outputLayer[0] << "    Expected Output: " << training_outputs[i][0] << "\n";
            
    }     
      

    return 0;
}


