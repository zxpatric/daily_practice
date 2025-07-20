import yaml

if __name__ == "__main__":
   
    try:
        with open('resources/config.yaml', 'r') as file:
            config_data = yaml.safe_load(file) # Use safe_load for security
        
        print("Loaded Configuration:")
        print(config_data)

        # Accessing specific values
        print(f"\nDatabase Host: {config_data['database']['host']}")
        print(f"First Table: {config_data['database']['tables'][0]}")

    except FileNotFoundError:
        print("Error: config.yaml not found.")
    except yaml.YAMLError as e:
        print(f"Error parsing YAML: {e}")


    python_data = {
        'server': {
            'name': 'web_server_01',
            'ip_address': '192.168.1.100',
            'ports': [80, 443]
        },
        'environment': 'production'
    }

    try:
        with open('resources/output.yaml', 'w') as file:
            yaml.dump(python_data, file, default_flow_style=False, sort_keys=False) # default_flow_style=False for block style
        print("\nData successfully written to output.yaml")

    except yaml.YAMAMLError as e:
        print(f"Error writing YAML: {e}")