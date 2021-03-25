using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class MoveAndSpawnRoad : MonoBehaviour
{
    public float speed = 2.5f;
    public GameObject road;
    void Update()
    {
        transform.Translate(Vector3.down * speed * Time.deltaTime);

        if (transform.position.y < -11.3f)
        {
            Instantiate(road, new Vector3(0, 11f, 0), Quaternion.identity);
            Destroy(gameObject);

        }
    }
}
