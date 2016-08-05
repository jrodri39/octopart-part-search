#!/bin/bash
rm -f csv_data_to_import.csv
NUMPARTS=$(wc -l < partslist.txt)
ITERPART=0
while IFS='' read -r line || [[ -n "$line" ]]; do \
  ITERPART=$((ITERPART+1))
  echo  "$line is $ITERPART of $NUMPARTS" 
  curl -G http://octopart.com/api/v3/parts/search \
  -d q=$line \
  -d apikey=$OCTOPART_API_KEY \
  -d pretty_print=true \
  -d limit=100 \
  -o results.txt \
  -d include[]=descriptions \
  -d incude[]=short_description \
  -d facet[fields][descriptions.value][include]=true \
  -d spec_drilldown[include]=true \
  -d spec_drilldown[limit]=100 \
  -d facet[fields][specs.tripping_current.value][include]=true \
  -d facet[fields][specs.vdg_drain_to_gate_voltage.value][include]=true \
  -d facet[fields][specs.vds_drain_to_source_voltage.value][include]=true \
  -d facet[fields][specs.viewing_angle.value][include]=true \
  -d facet[fields][specs.voltage_nodes.value][include]=true \
  -d facet[fields][specs.voltage_rating_ac.value][include]=true \
  -d facet[fields][specs.voltage_rating_dc.value][include]=true \
  -d facet[fields][specs.voltage_rating_transient.value][include]=true \
  -d facet[fields][specs.wavelength.value][include]=true \
  -d facet[fields][specs.weight.value][include]=true \
  -d facet[fields][specs.wire_gauge.value][include]=true 
  ./filter_and_csv
done < "partslist.txt"
