#ifndef STELLA_VSLAM_IO_MAP_DATABASE_IO_BASE_H
#define STELLA_VSLAM_IO_MAP_DATABASE_IO_BASE_H

#include "stella_vslam/data/bow_vocabulary.h"

#include <string>
#include <vector>
#include <cstdint>

namespace stella_vslam {

namespace data {
class camera_database;
class orb_params_database;
class bow_database;
class map_database;
} // namespace data

namespace io {

class map_database_io_base {
public:
    /**
     * Save the map database
     */
    virtual bool save(const std::string& path,
                      const data::camera_database* const cam_db,
                      const data::orb_params_database* const orb_params_db,
                      const data::map_database* const map_db)
        = 0;

    /**
     * Save the map database to memory bytes (msgpack format)
     * Non-blocking export support: serialize to memory instead of file
     */
    virtual bool save_to_bytes(std::vector<uint8_t>& out,
                               const data::camera_database* const cam_db,
                               const data::orb_params_database* const orb_params_db,
                               const data::map_database* const map_db)
        = 0;

    /**
     * Load the map database
     */
    virtual bool load(const std::string& path,
                      data::camera_database* cam_db,
                      data::orb_params_database* orb_params_db,
                      data::map_database* map_db,
                      data::bow_database* bow_db,
                      data::bow_vocabulary* bow_vocab)
        = 0;
};

} // namespace io
} // namespace stella_vslam

#endif // STELLA_VSLAM_IO_MAP_DATABASE_IO_BASE_H
