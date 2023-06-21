#ifndef STAR_MAIN_MIXER_HPP
#define STAR_MAIN_MIXER_HPP

#include "StarMixer.hpp"
#include "StarGameTypes.hpp"

namespace Star {

STAR_CLASS(UniverseClient);
STAR_CLASS(MainMixer);

class MainMixer {
public:
  MainMixer(unsigned sampleRate, unsigned channels);

  void setUniverseClient(UniverseClientPtr universeClient);

  void update(bool muteSfx = false, bool muteMusic = false);

  MixerPtr mixer() const;

  void setVolume(float volume, float rampTime = 0.0f);
  void read(int16_t* sampleData, size_t frameCount);

private:
  UniverseClientPtr m_universeClient;
  MixerPtr m_mixer;
  Set<MixerGroup> m_mutedGroups;
  Map<MixerGroup, float> m_groupVolumes;
};

}

#endif