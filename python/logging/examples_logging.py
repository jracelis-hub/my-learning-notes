import logging
import


# Create a Logger instance
logger: logging.Logger = logging.getLogger(__name__)

logger.basicConfig(filename = 'logs\\logger.log', level = logging.DEBUG)

# Set the logging attribute instance
# This is the state in which the event will be logged
# Anything below DEBUG will not trigger and event to be logged
logger.setLevel(logging.DEBUG)

# To add handlers
logger.addHandler(enter_name_of_handler)


file_handler = logging.FileHandler(security.ProdSec.work_order.log)
file_handler.setLevel(logging.DEBUG)
