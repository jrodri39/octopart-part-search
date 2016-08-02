#include <iostream>
#include "json.hpp"
#include <fstream>
#include <sstream>
#include <string>

using json = nlohmann::json;

int main(){
  //variables
  int n_spec_elements = 0;  // Number of elements for the array
  int n_specs = 0;          // Number of technical spec categories
  std::string temp_str;
  
  //open the file that contains the JSON data
  std::ifstream infile("results.txt", std::ifstream::in);
  //Declare a variable so that it can store a string
  std::stringstream buffer;
  //as long as the file is open and the string stream is good import to string
  if(infile.is_open() == true && buffer.good()){
    buffer << infile.rdbuf();
  }
  //create JSON object from the string
  auto j = json::parse(buffer.str());
  //close the file
  infile.close();
  //Create a file that will output/append the results into
  std::ofstream outfile("csv_data_to_import.csv", std::ofstream::out | std::ofstream::app);   
  if( outfile.is_open()){
/*
    //This will output the description with the largest count
    //outfile \
    << std::setw(2) \
    << j["facet_results"]["fields"]["descriptions.value"]["facets"][1]["value"] \
    << std::endl; 
*/    
   
    
    //Create Array for the name of each spec
    std::string specs[] = {
    "specs.access_time.value",
    "specs.actuator_length.value",
    "specs.actuator_type.value",
    "specs.antenna_connection.value",
    "specs.architecture.value",
    "specs.available_channels.value",
    "specs.bandwidth.value",
    "specs.bits.value",
    "specs.breakdown_voltage.value",
    "specs.breakdown_voltage_collector_to_base.value",
    "specs.breakdown_voltage_collector_to_emitter.value",
    "specs.breakdown_voltage_drain_to_source.value",
    "specs.breakdown_voltage_gate_to_source.value",
    "specs.cable_length.value",
    "specs.capacitance.value",
    "specs.capacitance_per_foot.value",
    "specs.capacitance_tolerance.value",
    "specs.carry_current.value",
    "specs.case_package.value",
    "specs.case_package_si.value",
    "specs.character_size_height.value",
    "specs.character_size_width.value",
    "specs.china_rohs.value",
    "specs.clock_speed.value",
    "specs.cmrr.value",
    "specs.coil_current.value",
    "specs.coil_power_ac.value",
    "specs.coil_power_dc.value",
    "specs.coil_resistance.value",
    "specs.coil_voltage.value",
    "specs.coil_voltage_ac.value",
    "specs.color.value",
    "specs.conductor_material.value",
    "specs.contact_current_rating.value",
    "specs.contact_material.value",
    "specs.contact_plating.value",
    "specs.contact_resistance.value",
    "specs.contact_style.value",
    "specs.contact_voltage_rating_dc.value",
    "specs.contacts_type.value",
    "specs.cord_length.value",
    "specs.core.value",
    "specs.core_architecture.value",
    "specs.core_size.value",
    "specs.core_subarchitecture.value",
    "specs.current_rating.value",
    "specs.data_rate.value",
    "specs.dielectric_characteristic.value",
    "specs.dielectric_material.value",
    "specs.dielectric_strength.value",
    "specs.dielectric_withstanding_voltage.value",
    "specs.drivers_per_package.value",
    "specs.dropout_voltage.value",
    "specs.elv_compliant.value",
    "specs.equivalent_series_resistance_esr.value",
    "specs.flammability_rating.value",
    "specs.flash_memory_bytes.value",
    "specs.forward_current.value",
    "specs.forward_voltage.value",
    "specs.fram_memory_bytes.value",
    "specs.frequency.value",
    "specs.frequency_stability.value",
    "specs.frequency_tolerance.value",
    "specs.gain.value",
    "specs.gate_charge.value",
    "specs.gate_to_source_threshold_voltage.value",
    "specs.gbw.value",
    "specs.gender.value",
    "specs.glow_wire_compliant.value",
    "specs.halogen_free_status.value",
    "specs.holding_current.value",
    "specs.housing_color.value",
    "specs.housing_material.value",
    "specs.housing_type.value",
    "specs.id_continuous_drain_current.value",
    "specs.inductance.value",
    "specs.inductance_tolerance.value",
    "specs.input_bias_current.value",
    "specs.input_capacitance.value",
    "specs.input_current.value",
    "specs.input_impedance.value",
    "specs.input_offset_drift.value",
    "specs.input_offset_voltage.value",
    "specs.input_power.value",
    "specs.input_voltage_dc.value",
    "specs.insulation_material.value",
    "specs.insulation_resistance.value",
    "specs.isolation_voltage.value",
    "specs.jacket_material.value",
    "specs.lead_free_status.value",
    "specs.lead_length.value",
    "specs.lens_color.value",
    "specs.lens_type.value",
    "specs.lifecycle_status.value",
    "specs.load_capacitance.value",
    "specs.load_current.value",
    "specs.logic_type.value",
    "specs.luminous_intensity.value",
    "specs.mated_height.value",
    "specs.material.value",
    "specs.memory_size.value",
    "specs.mil_spec.value",
    "specs.mounting_angle.value",
    "specs.mounting_style.value",
    "specs.negative_supply_voltage.value",
    "specs.number_of_adcs.value",
    "specs.number_of_bits.value",
    "specs.number_of_channels.value",
    "specs.number_of_circuits.value",
    "specs.number_of_conductors.value",
    "specs.number_of_contacts.value",
    "specs.number_of_dacs.value",
    "specs.number_of_detents.value",
    "specs.number_of_fibers.value",
    "specs.number_of_gates.value",
    "specs.number_of_i_o_pins.value",
    "specs.number_of_mating_cycles.value",
    "specs.number_of_outlets.value",
    "specs.number_of_outputs.value",
    "specs.number_of_positions.value",
    "specs.number_of_regulated_outputs.value",
    "specs.number_of_rows.value",
    "specs.number_of_slots.value",
    "specs.number_of_uart.value",
    "specs.operating_force.value",
    "specs.operating_temperature.value",
    "specs.operating_voltage.value",
    "specs.orientation.value",
    "specs.oscillator_type.value",
    "specs.output_capacitor_capacitance.value",
    "specs.output_capacitor_type.value",
    "specs.output_current.value",
    "specs.output_current_drive.value",
    "specs.output_power.value",
    "specs.output_type.value",
    "specs.output_voltage.value",
    "specs.packaging.value",
    "specs.part_family.value",
    "specs.peak_wavelength.value",
    "specs.pin_count.value",
    "specs.pin_pitch.value",
    "specs.polarity.value",
    "specs.positive_supply_voltage.value",
    "specs.power_consumption.value",
    "specs.power_dissipation.value",
    "specs.power_rating.value",
    "specs.processor_type.value",
    "specs.propagation_delay_max.value",
    "specs.psrr.value",
    "specs.q_factor.value",
    "specs.quiescent_current.value",
    "specs.ram_bytes.value",
    "specs.rds_drain_to_source_resistance_on.value",
    "specs.reach_svhc_compliance.value",
    "specs.release_force.value",
    "specs.resistance.value",
    "specs.resistance_tolerance.value",
    "specs.resloution_pulses_revolution.value",
    "specs.resolution_bits.value",
    "specs.resonant_frequency.value",
    "specs.rise_fall_time.value",
    "specs.rise_time.value",
    "specs.rohs_status.value",
    "specs.sample_rate.value",
    "specs.seal.value",
    "specs.self_resonant_frequency.value",
    "specs.settling_time.value",
    "specs.shielding.value",
    "specs.shielding_type.value",
    "specs.shrouded.value",
    "specs.size_diameter.value",
    "specs.size_height.value",
    "specs.size_inner_diameter.value",
    "specs.size_length.value",
    "specs.size_thickness.value",
    "specs.size_width.value",
    "specs.slew_rate.value",
    "specs.standby_current.value",
    "specs.static_current.value",
    "specs.supply_current.value",
    "specs.supply_current_per_channel.value",
    "specs.supply_voltage_ac.value",
    "specs.supply_voltage_dc.value",
    "specs.switching_current.value",
    "specs.switching_frequency.value",
    "specs.switching_voltage.value",
    "specs.temperature_coefficient.value",
    "specs.termination_style.value",
    "specs.test_text_attribute.value",
    "specs.thermal_resistance.value",
    "specs.thermal_shutdown.value",
    "specs.threshold_voltage.value",
    "specs.time_to_trip.value",
    "specs.topology.value",
    "specs.tripping_current.value",
    "specs.vdg_drain_to_gate_voltage.value",
    "specs.vds_drain_to_source_voltage.value",
    "specs.viewing_angle.value",
    "specs.voltage_nodes.value",
    "specs.voltage_rating_ac.value",
    "specs.voltage_rating_dc.value",
    "specs.voltage_rating_transient.value",
    "specs.wavelength.value",
    "specs.weight.value",
    "specs.wire_gauge.value"
    };

    //Number of technical specifications
    n_specs = (sizeof(specs)/sizeof(specs[0]));
    //int n_specs2 = specs.size();
    //DEBUG//outfile << "number if n_specs is : " << n_specs << std::endl;
    //outfile << "number if n_specs2 is : " << n_specs2 << std::endl;
    
    //Number of elements found for the spec
    n_spec_elements = j["facet_results"]["fields"][specs[18]]["facets"].size();
    //DEBUG//outfile << "number if n_spec_elements is : " << n_spec_elements << std::endl;

  
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
    
    //outfile << j["facet_results"]["fields"][specs[18]]["facets"][0]["value"] << std::endl;
    
    //close the output file
    outfile.close();
    }else{
    std::cerr << "Output file was not able to be opened" <<std::endl;
    }
  return 0;
}
