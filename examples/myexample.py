import numpy as np
from hanabi_learning_environment import pyhanabi

def print_observation(observation: pyhanabi.HanabiObservation):
    """Print some basic information about an agent observation."""
    print("--- Observation ---")
    print(observation)

    print("### Information about the observation retrieved separately ###")
    print("### Current player, relative to self: {}".format(
        observation.cur_player_offset()))
    print("### Observed hands: {}".format(observation.observed_hands()))
    print("### Card knowledge: {}".format(observation.card_knowledge()))
    print("### Discard pile: {}".format(observation.discard_pile()))
    print("### Fireworks: {}".format(observation.fireworks()))
    print("### Deck size: {}".format(observation.deck_size()))
    move_string = "### Last moves:"
    for move_tuple in observation.last_moves():
      move_string += " {}".format(move_tuple)
    print(move_string)
    print("### Information tokens: {}".format(observation.information_tokens()))
    print("### Life tokens: {}".format(observation.life_tokens()))
    print("### Legal moves: {}".format(observation.legal_moves()))
    print("--- EndObservation ---")

if __name__ == "__main__":
    print("hello world")
    assert pyhanabi.cdef_loaded(), "cdef failed to load"
    assert pyhanabi.lib_loaded(), "lib failed to load"

    game = pyhanabi.HanabiGame({"players": 2, "random_start_player": True})
    print(game.num_players())

    state = game.new_initial_state()

    observation = state.observation(state.cur_player())
    print_observation(observation)