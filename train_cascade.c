#include <stdio.h>
#include "fann.h"

int main()
{
        struct fann *ann;
        struct fann_train_data *train_data;
        const float desired_error = (const float) 0.003;
        const unsigned int max_epochs = 500000;
        const unsigned int epochs_between_reports = 1;
        enum fann_activationfunc_enum activation[2];


        printf("Reading Data\n");
        train_data = fann_read_train_from_file("data.learn");

        //fann_scale_train_data(train_data, -1, 1);

        printf("Creating Network\n");
        ann = fann_create_shortcut(2, fann_num_input_train_data(train_data),    fann_num_output_train_data(train_data));
        fann_print_parameters(ann);

        printf("Training Network\n");
        fann_cascadetrain_on_file(ann, "data.learn", max_epochs, epochs_between_reports, desired_error);

        printf("Saving Network as data_cascade.net.\n");
        fann_save(ann, "data_cascade.net");

        printf("Cleaning up.\n");
        fann_destroy_train(train_data);
        fann_destroy(ann);

        return 0;
}
