#include "utils.h"

uint32_t extract_tag(uint32_t address, const CacheConfig& cache_config) {
  // TODO

  uint32_t offset = cache_config.get_num_block_offset_bits();
  uint32_t idx = cache_config.get_num_index_bits();

  if (idx + offset == 32){
		return 0;
	}

	address = address >> (idx + offset);
	return address;
}

uint32_t extract_index(uint32_t address, const CacheConfig& cache_config) {
  // TODO
  uint32_t tag = cache_config.get_num_tag_bits();
	uint32_t offset = cache_config.get_num_block_offset_bits();

  if(tag + offset == 32){
		return 0;
	}

	address = address << tag;
	address = address >> (tag + offset);

  return address;

}

uint32_t extract_block_offset(uint32_t address, const CacheConfig& cache_config) {
  // TODO
  uint32_t tag = cache_config.get_num_tag_bits();
  uint32_t idx = cache_config.get_num_index_bits();

  if(tag + idx == 32){
    return 0;
  }

  address = address << (tag + idx);
  address = address >> (tag + idx);

  return address;
}
