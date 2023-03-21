//
// Created by patatofour on 21/03/23.
//

#ifndef ARCADE_MUSIC_HPP
#define ARCADE_MUSIC_HPP

#include "IMusic.hpp"

namespace Arcade::Graph
{
    class Music : public IMusic
    {
        public:
        Music(std::string path, std::string id);
        ~Music() override = default;

        [[nodiscard]] const std::string &getPath() const override;
        [[nodiscard]] const std::string &getId() const override;
        [[nodiscard]] bool getLoop() const override;
        void setLoop(bool loop) override;
        [[nodiscard]] bool getIsPlaying() const override;
        void setIsPlaying(bool isPlaying) override;
        [[nodiscard]] float getVolume() const override;
        void setVolume(float volume) override;

        protected:
        std::string _path;
        std::string _id;
        bool _loop;
        bool _isPlaying;
        float _volume;
    };
} // namespace Arcade::Graph

#endif // ARCADE_MUSIC_HPP
