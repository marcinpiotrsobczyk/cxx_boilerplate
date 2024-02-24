#include <example/tools.hpp>

#include <boost/filesystem.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/deque.hpp>
#include <boost/interprocess/containers/flat_map.hpp>
#include <boost/interprocess/containers/flat_set.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/managed_mapped_file.hpp>
#include <boost/interprocess/sync/file_lock.hpp>
#include <boost/interprocess/sync/interprocess_sharable_mutex.hpp>
#include <boost/interprocess/sync/sharable_lock.hpp>
#include <gtest/gtest.h>

#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <utility>
#include <vector>

namespace {

constexpr std::size_t ENTRIES = 100000;
constexpr std::size_t BLOB_LENGTH = 100;
constexpr std::size_t ITERATIONS = 10;
namespace bip = boost::interprocess;
namespace bfs = boost::filesystem;

template <typename T>
using allocator = bip::allocator<T, bip::managed_mapped_file::segment_manager>;
using blob = bip::vector<char, allocator<char>>;
using blob_map = bip::map<blob, blob, std::less<blob>,
                          allocator<std::pair<const blob, blob>>>;
} // namespace

TEST(AllocatorTest, ManagedMappedFileSmokeTest) {
  auto abs_path = bfs::absolute("shared_memory.bin");
  std::size_t shared_file_size = 1024 * 1024 * 256;
  std::unique_ptr<bip::managed_mapped_file> _segment;
  // bfs::remove( abs_path );
  _segment.reset(new bip::managed_mapped_file(bip::open_or_create,
                                              abs_path.generic_string().c_str(),
                                              shared_file_size));

  typedef bip::allocator<char, bip::managed_mapped_file::segment_manager>
      CharAllocator;
  typedef bip::basic_string<char, std::char_traits<char>, CharAllocator>
      MyString;
  MyString *s = _segment->find_or_construct<MyString>("String")(
      "Hello!", _segment->get_segment_manager());
  s->insert(5, ", world");
  std::cout << *s << '\n';

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 255);
  blob_map *my_map_ptr;
  blob *k;
  blob *v;
  my_map_ptr = _segment->find_or_construct<blob_map>("my_map")(
      allocator<blob_map>(_segment->get_segment_manager()));
  k = _segment->find_or_construct<blob>("k")(
      allocator<blob>(_segment->get_segment_manager()));
  v = _segment->find_or_construct<blob>("v")(
      allocator<blob>(_segment->get_segment_manager()));

  k->resize(BLOB_LENGTH);
  v->resize(BLOB_LENGTH);

  auto fill_with_randomize_values = [&distrib, &gen](blob &b) {
    for (std::size_t i = 0; i < b.size(); i++)
      b[i] = static_cast<char>(distrib(gen));
  };

  // auto get_blob_content = [](blob &b) -> std::string {
  //   std::string s('\0', b.size());
  //   for (std::size_t i = 0; i < b.size(); i++)
  //     s[i] = b[i];
  //   return s;
  // };

  for (std::size_t i = 0; i < ENTRIES; i++) {
    fill_with_randomize_values(*v);
    fill_with_randomize_values(*k);
    // std::string s = get_blob_content(*k);
    // std::cout << "insert " << s << " blob as string" << std::endl;
    auto p = std::pair<const blob, blob>{*k, *v};
    my_map_ptr->insert(p);
  }
}
