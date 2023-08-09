#pragma once

#include <optional>
#include <vector>

struct IndexedDatagram {
    size_t index;
    std::optional<std::span<char>> data;
};

IndexedDatagram MakeCutIndexedDatagram(const IndexedDatagram& datagram, size_t to_cut) {
    return IndexedDatagram{datagram.index, datagram.data->subspan(to_cut)};
}

IndexedDatagram MakeEmptyDatagram(const IndexedDatagram& datagram) {
    return IndexedDatagram{datagram.index, std::nullopt};
}
