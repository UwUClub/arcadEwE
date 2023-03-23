//
// Created by patatofour on 21/03/23.
//

#ifndef ARCADE_MUSIC_HPP
#define ARCADE_MUSIC_HPP

#include "IMusic.hpp"
#include "Component.hpp"

namespace Arcade::Graph
{
    class Music : public IMusic
    {
        public:
        Music(const std::string &path, const std::string &id);
        ~Music() override = default;

        [[nodiscard]] const std::string &getPath() const override;
        [[nodiscard]] ECS::CompType getType() const override;
        void setPath(const std::string &path) override;
        [[nodiscard]] const std::string &getId() const override;
        [[nodiscard]] bool getLoop() const override;
        void setLoop(bool loop) override;
        [[nodiscard]] bool getIsPlaying() const override;
        void setIsPlaying(bool isPlaying) override;
        [[nodiscard]] float getVolume() const override;
        void setVolume(float volume) override;

        protected:
        const ECS::CompType _type{ECS::CompType::MUSIC};
        std::string _path;
        const std::string _id;
        bool _loop;
        bool _isPlaying;
        float _volume;
    };
} // namespace Arcade::Graph

#endif // ARCADE_MUSIC_HPP
