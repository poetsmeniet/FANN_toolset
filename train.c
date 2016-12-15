#include "fann.h"
//gcc xor_train.c -o xor_train.o -lfann -lm
//red=0, blue=1 max. using 460 inputs of each file
int main()
{
    //const unsigned int num_input = 20000;
    const unsigned int num_input = 10000;

    const unsigned int num_output = 1;
    const unsigned int num_layers = 3;
    const unsigned int num_neurons_hidden = 100;
    //const float desired_error = (const float) 0.001;
    const float desired_error = (const float) 0.003;
    const unsigned int max_epochs = 500000;
    const unsigned int epochs_between_reports = 1000;

    struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

    fann_train_on_file(ann, "data.learn", max_epochs, epochs_between_reports, desired_error);

    fann_save(ann, "data.net");

    fann_destroy(ann);

    return 0;
}
