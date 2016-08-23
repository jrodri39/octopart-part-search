# octopart-part-search
This is [POWERED BY OCTOPART](https://octopart.com/api/home)




## Synopsis

This will create a Comma-Separated Values (.CSV) file that can be imported to 
excel or similar program. The .csv file will have the different descriptions 
OctoPart.com has found for each part number from the provided Part Number list.
It does not gurantee that octopart found the exact part you have but shows 
you the descriptions that matched the part number from its database.


## Code Example
```
    //print the query that was used for the search
    outfile << j["request"]["q"] << std::endl;

    //This will pull every description for the parts search sorted by count
    outfile << ",Description,"; //header
    for( unsigned int i = 0; \
    i < j["facet_results"]["fields"]["descriptions.value"]["facets"].size();\
    i++){
      outfile \
      << j["facet_results"]["fields"]["descriptions.value"]["facets"][i]["value"] \
      <<", ";
    }
    outfile << std::endl;

    for(  int i = 0; i < n_specs;  i++){
      //Number of elements found for the spec
      temp_str = specs[i];
      n_spec_elements = j["facet_results"]["fields"][temp_str.c_str()]["facets"].size();
      outfile << ", " << specs[i] << ", ";

      for (int t = 0; t < n_spec_elements ; t++){
        outfile \
        << j["facet_results"]["fields"][temp_str.c_str()]["facets"][t ]["value"]\
        << ", ";
      }
      outfile << std::endl;
    }

```

## Motivation
Some systems use an old database that was created in excel to keep track of 
electronic components in their inventory. They may not have kept track of
the descriptions of these parts on hand nor did they keep track of min/max
values of their technical specifications. This was created with the intention
to update an excel database with part descriptions and critical min/max 
values.


## Installation

Clone or copy all the files from the repository and place in your local
directory. You will have to provide a .txt file with the name 
"partslist.txt". This project already provides you with one, but you 
will have to modify it with your own part numbers. You can simply copy
and paste from your excel file into the text file. 

After you collect all the files into a folder in your local drive you can start
these steps.

Replace $OCTOPART_API_KEY (from octopartapi.sh file)with the api key that must
be retrieved after signing up at [OCTOPART](https://octopart.com/api/home)
On the command line type:
```
make clean
```
```
make
```
```
sh octopartapi.sh
```



## API Reference
API reference can be found at [OCTOPART](https://octopart.com/api/home) 

## Tests

Describe and show how to run the tests with code examples.

## Contributors

Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable.

## License

A short snippet describing the license (MIT, Apache, etc.)

