#include "cacheblock.h"

uint32_t Cache::Block::get_address() const {
  // TODO
  size_t offset = _cache_config.get_num_block_offset_bits();
  size_t idx = _cache_config.get_num_index_bits();
  uint32_t tag = get_tag();
  uint32_t address = 0;

  address = address | tag;
  address = address << idx;
  address = address | _index;
  address = address << offset;

  return address;


}
