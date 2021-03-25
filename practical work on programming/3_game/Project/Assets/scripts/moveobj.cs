using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class moveobj : MonoBehaviour
{
    public float speed = 1.5f;
    void FixedUpdate()
    {
        transform.Translate(Vector3.forward * speed * Time.deltaTime);

        if (transform.position.y < -8) 
        {
            Destroy(gameObject);
        }
    }
}
